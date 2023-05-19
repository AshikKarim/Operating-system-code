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
}
