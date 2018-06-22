var attempt = document.getElementById("COLE_O_ID_AQUI").firstChild;
var questions = [];

function getImage(node) {
	let img = '';

	if (!node)
		return;

	if (node.tagName === "IMG")
		img = node.src;

	for (let i = 0; i < node.childNodes.length; i++)
		img += getImage(node.childNodes[i]);

	return img;
}

for (let i = 0; i < attempt.childNodes.length - 1; i++) {
	if (attempt.childNodes[i].tagName === 'DIV') {
		let data = attempt.childNodes[i].childNodes[1];
		let question = {
			pergunta: '',
			imagem: '',
			alternativas: '',
			resposta: ''
		};

		question.pergunta = data.childNodes[0].childNodes[2].innerText;
		question.imagem = getImage(data.childNodes[0].childNodes[2]);
		question.alternativas = data.childNodes[0].childNodes[3].innerText;
		question.resposta = data.childNodes[1].childNodes[1].childNodes[1].innerText;

		questions.push(question);
	}
}

JSON.stringify(questions); 