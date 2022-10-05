    IMAGE FILTER

video-demo:

    https://youtu.be/vI1Ro-pzvH0

Desciption:

    My final project is a web-based image filter, in which the user first as to register and log in, to then be able to upload an image, and filter it as he likes.
    The website as filters of: sepia, grayscale, opacity, blur, HUE rotate, Invert colors, Saturation, Contrast and brightness.
    To support the user the website also as three buttoms, where one of them zooms in, the other zooms out, and the last one resets all filters to get the original photo back.
    Python files:
        The "app.py" file is the "brain" of the whole website its there that the Flask framework is being stored and the file that redirects the user to the correct page and stores the registrations in another file named "files.db", using SQL.
        Here we have the login function, which andles everythin about the user login, from checking the inputs to see if they match the SQL file to the redirection (if successfull), there is the registration function that takes care of the registration and inserts the inputs if well given into the SQl file, there's also the logout function which andles the logout of the website and there's the editor function which simply redirects the user to "editor.html" because the rest is handled by javascript in that part of the website.
        The "helpers.py" as the name suggests its a file that gives support to the "app.py" file, this file comes in action when something goes wrong to make the user log in to the website before being able to filter the image.

    Templates folder:
        In this folder there are five HTML files which are the "face" of the website, there's one for the registration with three input spaces, which are the "username" the "password" and the "password confirmation" and a submit buttom, other for the login with two input spaces "username" and "password" and a submit buttom, other for the editing with nine sliders to change the values of each one of the filters, there are also four buttoms, where two of them are to handle the zooms, one is to reset the filters and the last if to upload the image, other file for the apology when something goes wrong which simply shows a picture and a text saying what went wrong, and the one that is used as the skeleton because all the others are made from this one, which is the "layout.hml", this one contains the nav-bar, part of the title and the css file of all the others.

    static folder:
        Here we have three files, the first "script.js" is the scipt file to do all nine types of filters included, this file is used only by "editor.html" file, the second one "style.css" is used by all of the HTML files to make the nav-bar prettier and chance the colors of the title, and the styles.css is used only by "editor.html" to apply all the filters in the image.

    Flask_session folder:
        This folder is used by Flask to store the "cookies" of the website to make the website better.