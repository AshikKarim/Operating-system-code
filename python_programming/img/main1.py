import cv2
import face_recognition
import pandas as pd
import os

# Create an empty DataFrame to store the attendance data
attendance_df = pd.DataFrame(columns=['Name', 'Date', 'Time'])

# Load the images of the students and encode their faces
students_dir = 'students_images'
student_images = [f for f in os.listdir(students_dir) if f.endswith('.jpg')]
student_encodings = []
student_names = []
for image_file in student_images:
    image_path = os.path.join(students_dir, image_file)
    student_image = face_recognition.load_image_file(image_path)
    student_encoding = face_recognition.face_encodings(student_image)[0]
    student_encodings.append(student_encoding)
    student_names.append(os.path.splitext(image_file)[0])

# Initialize the camera
camera = cv2.VideoCapture(0)

while True:
    # Capture a frame from the camera
    ret, frame = camera.read()
    
    # Convert the frame to RGB
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    
    # Detect the faces in the frame
    face_locations = face_recognition.face_locations(rgb_frame)
    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)
    
    # Check if any of the detected faces match with the students
    for face_encoding, face_location in zip(face_encodings, face_locations):
        matches = face_recognition.compare_faces(student_encodings, face_encoding)
        if True in matches:
            # Get the name of the matched student
            matched_student_name = student_names[matches.index(True)]
            
            # Get the current date and time
            date = pd.Timestamp.now().strftime('%Y-%m-%d')
            time = pd.Timestamp.now().strftime('%H:%M:%S')
            
            # Add the attendance record to the DataFrame
            attendance_df = attendance_df.append({'Name': matched_student_name, 'Date': date, 'Time': time}, ignore_index=True)
            
            # Draw a rectangle around the detected face and display the name of the student
            top, right, bottom, left = face_location
            cv2.rectangle(frame, (left, top), (right, bottom), (0, 255, 0), 2)
            cv2.putText(frame, matched_student_name, (left, top-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
    
    # Display the frame
    cv2.imshow('Attendance', frame)
    
    # Exit the loop if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close the window
camera.release()
cv2.destroyAllWindows()

# Save the attendance data to an Excel sheet
attendance_file = 'attendance.xlsx'
attendance_df.to_excel(attendance_file, index=False)
