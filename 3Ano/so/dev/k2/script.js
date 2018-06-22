(function() {

    var container = document.querySelector('#container');
    var content = '';
    var db = '';
    var xhr = new XMLHttpRequest();

    xhr.open('GET', 'database.json');

    xhr.onload = function() {
        if (xhr.status >= 200 && xhr.status < 400) {
            db = xhr.responseText;
            console.log(xhr.responseText);
            db = db.replace(/\s+/g, ' ').replace(/\&nbsp\;+/g, ' ').replace(//g, '-').replace(/–/g, '-').replace(//g, "'").replace(//g, "'").replace(/“/g, "'").replace(/”/g, "'").replace(/\\n\\n+\s*[\\n\\n|\\n]*/g, '\\n').replace(/\\n+\s*[\\n\\n|\\n]*/g, '\\n');
            console.log(db);
            db = JSON.parse(db);
            console.log(db);
            renderHTML();
        } else {
            console.log("Server error");
        }
    }

    xhr.send();

    function renderHTML() {
        db = db.filter((question, index, self) => self.findIndex(q => q.pergunta.replace(/_+/g, '').toUpperCase() === question.pergunta.replace(/_+/g, '').toUpperCase()) === index);
        console.log(db);

        for (let i = 0; i < db.length; i++) {
            db[i].pergunta = db[i].pergunta.replace(/\n+/g, '<br>');
            db[i].alternativas = db[i].alternativas.replace(/\n+/g, '<br>');
            db[i].resposta= db[i].resposta.replace(/\.+\s*\.*/g, '. ').replace(/\n+/g, '<br>');

            content += '<div class="question"><span>' + (i + 1) + '.</span><p>' + db[i].pergunta + '</p>' + /*(db[i].imagem !== '' ? '<img src="' + db[i].imagem + '">' : '') +*/ '<p>' + db[i].alternativas + '</p>' + '<p>' + db[i].resposta + '</p></div>';
        }

        console.log(content);
        container.insertAdjacentHTML('beforeend', content);
    }

})();
