// Get the login and signup forms
const loginForm = document.getElementById("login-form");
const signupForm = document.getElementById("signup-form");

// Add an event listener to the login form
loginForm.addEventListener("submit", (event) => {
    event.preventDefault();
    // Get the username and password from the form
    const username = loginForm.elements.username.value;
    const password = loginForm.elements.password.value;
    // Check if the username and password are correct
    // If they are correct, redirect to the dashboard page
    // If they are not correct, show an error message
});

// Add an event listener to the signup form
signupForm.addEventListener("submit", (event) => {
    event.preventDefault();
    // Get the full name, email, username, and password from the form
    const fullname = signupForm.elements.fullname.value;
    const email = signupForm.elements.email.value;
    const username = signupForm.elements.username.value;
    const password = signupForm.elements.password.value;
    // Create a new user with the full name, email, username, and password
    // If the user is created successfully, redirect to the dashboard page
    // If there is an error, show an error message
});
/*
window.onload = function() {
    resizeElements();
    window.addEventListener('resize', resizeElements);
};

function resizeElements() {
    const header = document.querySelector('header');
    const main = document.querySelector('main');
    const footer = document.querySelector('footer');
    const windowHeight = window.innerHeight;
    const headerHeight = header.offsetHeight;
    const footerHeight = footer.offsetHeight;
    const mainHeight = windowHeight - headerHeight - footerHeight;

    main.style.minHeight = `${mainHeight}px`;
}*/
