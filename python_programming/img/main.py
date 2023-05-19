import cv2
import os
import numpy as np
import face_recognition
import mysql.connector

# Connect to the MySQL database
mydb = mysql.connector.connect(
  host="localhost",
  user="yourusername",
  password="yourpassword",
  database="students"
)

# Create a cursor object to execute SQL queries
mycursor = mydb.cursor()

# Create a table to store students' images
mycursor.execute("CREATE TABLE students_images (name VARCHAR(255), image BLOB)")

# Initialize the webcam
cap = cv2.VideoCapture(0)

# Load the known faces and encodings
known_faces = []
known_names = []
for filename in os.listdir('known_faces'):
    image = face_recognition.load_image_file('known_faces/'+filename)
    encoding = face_recognition.face_encodings(image)[0]
    known_faces.append(encoding)
    known_names.append(os.path.splitext(filename)[0])

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Find all the faces and face encodings in the frame
    face_locations = face_recognition.face_locations(frame)
    face_encodings = face_recognition.face_encodings(frame, face_locations)

    # Loop through each face in the frame
    for face_encoding, face_location in zip(face_encodings, face_locations):
        # Compare the face encoding with the known faces
        matches = face_recognition.compare_faces(known_faces, face_encoding)

        # Find the best match
        face_distances = face_recognition.face_distance(known_faces, face_encoding)
        best_match_index = np.argmin(face_distances)

        # If the face is a match, save the image to the database
        if matches[best_match_index]:
            name = known_names[best_match_index]
            image = cv2.imencode('.jpg', frame)[1].tostring()
            sql = "INSERT INTO students_images (name, image) VALUES (%s, %s)"
            val = (name, image)
            mycursor.execute(sql, val)
            mydb.commit()

    # Display the resulting frame
    cv2.imshow('Video', frame)

    # Exit loop on pressing 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the webcam and close the window
cap.release()
cv2.destroyAllWindows()

