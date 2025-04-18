function getCurrentRelativePath() {
    const url = window.location.pathname;
    return url.startsWith('/') ? url.substring(1) : url;
}

function setCookie(name, value, days) {
    const expires = new Date();
    expires.setDate(expires.getDate() + days);
    document.cookie = `${name}=${value}; expires=${expires.toUTCString()}; path=/`;
}

function getCookie(name) {
    const cookies = document.cookie.split(';').map(cookie => cookie.trim().split('='));
    const cookie = cookies.find(([key]) => key === name);
    return cookie ? cookie[1] : null;
}

function loadContent() {
    const toc = document.getElementById('toc');
    const tocButton = document.getElementById('tocButton');
    const headings = document.querySelectorAll('h2, h3, h4');

    const toggleButton = document.createElement('button');
    toggleButton.textContent = getCookie('tocShown') === 'true' ? 'Hide Content' : 'Show Content';
    //toggleButton.style.fontSize = "110%";
    toggleButton.style.padding = "5px";
    toggleButton.style.marginBottom = "10px";

    toggleButton.onclick = () => {
        const isShown = toc.style.display === 'block';
        toc.style.display = isShown ? 'none' : 'block';
        setCookie('tocShown', !isShown, 30);
        toggleButton.textContent = isShown ? 'Show Content' : 'Hide Content';
    };

    if (getCookie('tocShown') === 'true') {
        toc.style.display = 'block';
    } else {
        toc.style.display = 'none';
    }

    toc.innerHTML = '<h2 class="ignore-counter">Content:</h2><ul></ul>';
    const tocList = toc.querySelector('ul');
    let lastH2 = null, lastH3 = null;

    let someHeaders = false;

    headings.forEach((heading, index) => {
        if(!someHeaders) someHeaders = true;
        const listItem = document.createElement('li');
        const link = document.createElement('a');

        heading.id = `heading-${index}`;
        //link.href = "file:///" + getCurrentRelativePath() + `#heading-${index}`;
        link.href = `/${getCurrentRelativePath()}#heading-${index}`;
        link.textContent = heading.textContent;

        listItem.appendChild(link);

        if (heading.tagName === 'H2') {
            tocList.appendChild(listItem);
            lastH2 = document.createElement('ul');
            listItem.appendChild(lastH2);
            lastH3 = null;
        } else if (heading.tagName === 'H3' && lastH2) {
            lastH2.appendChild(listItem);
            lastH3 = document.createElement('ul');
            listItem.appendChild(lastH3);
        } else if (heading.tagName === 'H4' && lastH3) {
            lastH3.appendChild(listItem);
        }
    });
    if(someHeaders) {
    tocButton.appendChild(toggleButton);
    } else {
    toc.style.display = 'none';







    }
}
