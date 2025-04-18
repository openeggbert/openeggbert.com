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
    toggleButton.textContent = getCookie('tocShown') === 'false' ? 'Show Content' : 'Hide Content';
    toggleButton.style.fontSize = "125%";
    toggleButton.style.padding = "5px";
    toggleButton.style.marginBottom = "20px";

    toggleButton.onclick = () => {
        const isShown = toc.style.display === 'none';
        toc.style.display = isShown ? 'block' : 'none';
        setCookie('tocShown', !isShown, 30);
        toggleButton.textContent = isShown ? 'Hide Content' : 'Show Content';
    };

    if (getCookie('tocShown') === 'true') {
        toc.style.display = 'none';
    }

    toc.innerHTML = '<h2>Content:</h2><ul></ul>';
    const tocList = toc.querySelector('ul');
    let lastH2 = null, lastH3 = null;

    headings.forEach((heading, index) => {
        const listItem = document.createElement('li');
        const link = document.createElement('a');

        heading.id = `heading-${index}`;
        link.href = "file:///" + getCurrentRelativePath() + `#heading-${index}`;
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
    tocButton.appendChild(toggleButton);
}
