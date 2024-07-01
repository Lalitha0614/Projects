
    var loginForm, ccioLoginForm, toggleBtn; // Define variables in the global scope

    document.addEventListener("DOMContentLoaded", function() {
        loginForm = document.getElementById("login-form");
        ccioLoginForm = document.getElementById("CCIO-login-form");
        toggleBtn = document.getElementById("btn");
    });

    function CCIO_login() {
        loginForm.style.left = "-400px";
        ccioLoginForm.style.left = "50px";
        toggleBtn.style.left = "110px";
    }

    function login() {
        loginForm.style.left = "50px";
        ccioLoginForm.style.left = "450px";
        toggleBtn.style.left = "0";
    }

