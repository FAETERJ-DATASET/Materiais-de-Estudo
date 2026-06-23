var Configuracao = {
	velocidade: 300,
	tempoEstrelaAtiva: 5000,
	largura:15
}


var contexto;
var Canvas = {
	_init:function(){
		
		// Defindindo canvas
		var objCanvas = document.getElementById('canvas');
		contexto = objCanvas.getContext("2d");
		
		Canvas.maxWidth = parseInt(objCanvas.width);
		Canvas.maxHeight = parseInt(objCanvas.height);		
		Canvas._bg();
	},
	_bg:function(){
		contexto.clearRect(0,0,Canvas.maxWidth,Canvas.maxHeight);

		/* Criando um retangulo com degrade */
		contexto.beginPath();
		var gradient = contexto.createLinearGradient(Canvas.maxWidth, 0, 0, Canvas.maxHeight);
		gradient.addColorStop(0,'#ff5');
		gradient.addColorStop(1,'#f60');
		contexto.fillStyle = gradient;
		contexto.fillRect(0, 0, Canvas.maxWidth, Canvas.maxHeight);			
		contexto.closePath();
	},
	_preencher:function(){
		Canvas._bg();
		for(i=0;i<Snake.tamanho;i++){
			contexto.fillStyle = "#000";;
			contexto.beginPath();
			contexto.fillRect(Snake.corpo[i].x * Configuracao.largura, Snake.corpo[i].y * Configuracao.largura, Configuracao.largura, Configuracao.largura);			
			contexto.closePath();					
		}
		
		Snake._mover();
		
		Jogo.tempo += Configuracao.velocidade;
		if(Jogo.tempo % (Configuracao.velocidade*50) ==0) Estrelas._adicionar();
		
		Estrelas._preencher();
		Estrelas._capturar();
	}
}	



var Estrelas = {
	lista:new Array(),
	_adicionar:function(){
	
		var lugar_ocupado = true;
		var estrela_x, estrela_y;
		
		while(lugar_ocupado==true){
			lugar_ocupado = false;
			estrela_x = parseInt(Math.random()* (Canvas.maxWidth / Configuracao.largura));
			estrela_y = parseInt(Math.random()* (Canvas.maxHeight / Configuracao.largura));
			for(i=0;i<Snake.tamanho;i++){
				if(Snake.corpo[i].x == estrela_x && Snake.corpo[i].y == estrela_y) lugar_ocupado = true;
			}				
		}		
		Estrelas.lista.push({
			x:estrela_x,
			y:estrela_y,
			inicio:Jogo.tempo
		});
	},
	_preencher:function(){
		for(i=0;i<Estrelas.lista.length;i++){
			contexto.fillStyle = "#1D9F53";
			contexto.beginPath();
			contexto.fillRect(Estrelas.lista[i].x * Configuracao.largura, Estrelas.lista[i].y * Configuracao.largura, Configuracao.largura, Configuracao.largura);			
			contexto.closePath();					
		}	
		if(Estrelas.lista.length>0)	if(Estrelas.lista[0].inicio + Configuracao.tempoEstrelaAtiva < Jogo.tempo) Estrelas.lista.shift();	
	},
	_capturar:function(){
		for(i=0;i<Estrelas.lista.length;i++){
			if(Estrelas.lista[i].x == Snake.corpo[Snake.tamanho-1].x && Estrelas.lista[i].y == Snake.corpo[Snake.tamanho-1].y){
				Snake._crescer();
				Jogo.pontos += 500;
				return Estrelas._remover(i);
			}
		}	
	},
	_remover:function(Indice){
		for(i=Indice;i + 1<Estrelas.lista.length;i++){
			Estrelas.lista[i].x = Estrelas.lista[i+1].x;
			Estrelas.lista[i].y = Estrelas.lista[i+1].y;
		}	
		Estrelas.lista.pop();
	}
}




var Snake = {
	tamanho: 0, /* binario */
	direcao: 0, /* estilo css */
	ultimaDirecao: 0, /* ultima direcao do snake na funcao mover */
	corpo: new Array(),
	_mover:function(){
		Jogo._placar();
		
		var novo_x = Snake.corpo[Snake.tamanho-1].x;
		var novo_y = Snake.corpo[Snake.tamanho-1].y;
		if(Snake.direcao==0) novo_y--; // CIMA
		if(Snake.direcao==1) novo_x++; // DIREITA
		if(Snake.direcao==2) novo_y++; // BAIXO
		if(Snake.direcao==3) novo_x--;; // ESQUERDA
		Snake.ultimaDirecao = Snake.direcao;
		
		for(i=0;i<Snake.tamanho-1;i++){
			Snake.corpo[i].x = Snake.corpo[i+1].x;
			Snake.corpo[i].y = Snake.corpo[i+1].y;
			if(Snake.corpo[i].x==novo_x && Snake.corpo[i].y==novo_y) return Jogo._gameOver();			
		}
		
		Snake.corpo[Snake.tamanho-1].x = novo_x;
		Snake.corpo[Snake.tamanho-1].y = novo_y;
		
		// Verificando se bateu na parede
		if(Snake.corpo[Snake.tamanho-1].x * Configuracao.largura >= Canvas.maxWidth || Snake.corpo[Snake.tamanho-1].x < 0) return Jogo._gameOver();
		if(Snake.corpo[Snake.tamanho-1].y * Configuracao.largura >= Canvas.maxHeight || Snake.corpo[Snake.tamanho-1].y < 0) return Jogo._gameOver();
	},
	_crescer:function(){
		Snake.corpo.unshift({
			x:Snake.corpo[0].x-1,
			y:Snake.corpo[0].y
		},{
			x:Snake.corpo[0].x-1,
			y:Snake.corpo[0].y
		},{
			x:Snake.corpo[0].x-1,
			y:Snake.corpo[0].y
		});
		Snake.tamanho += 3;
	}
}



var Jogo = {
	play:'',
	pontos: 0,
	tempo: 0,
	_iniciar:function(){
		Snake.tamanho = 15;
		Snake.direcao = 1;
		Jogo.tempo = 0;
		Jogo.pontos = 0;
		Estrelas.lista = new Array();
		for(i=0;i<Snake.tamanho;i++){ Snake.corpo[i]={ x:i, y:0 } }	
		Jogo._play();
		document.getElementById('pontos').innerHTML = '0';
		document.getElementById('box_score').style.visibility = 'visible';		
	},
	_placar:function(){
		Jogo.pontos++;
		if(Jogo.pontos%10==0) document.getElementById('pontos').innerHTML = Jogo.pontos;
	},
	_play:function(){
		if(Jogo.play!='') clearInterval(Jogo.play);
		Jogo.play = setInterval(Canvas._preencher, Configuracao.velocidade);	
	},
	_gameOver:function(){
		if(Jogo.play!='') clearInterval(Jogo.play);
	},
	_pausar:function(){
		if(Jogo.play!=''){
			clearInterval(Jogo.play);
			Jogo.play = '';
		} else {
			Jogo._play();
		}	
	},
	_controles:function(e, event){
		if (window.event){  e = window.event; }
		switch(e.keyCode){
			case 73:
				Jogo._iniciar();
				e.preventDefault();
				break;
			case 80:
				Jogo._pausar();
				e.preventDefault();
				break;
			case 38:
				if(Snake.ultimaDirecao!=2) Snake.direcao = 0; // SETA PRA CIMA
				e.preventDefault();
				break;
			case 39:
				if(Snake.ultimaDirecao!=3) Snake.direcao = 1; // SETA PRA DIREITA
				e.preventDefault();
				break;
			case 40:
				if(Snake.ultimaDirecao!=0) Snake.direcao = 2; // SETA PRA BAIXO
				e.preventDefault();
				break;
			case 37:
				if(Snake.ultimaDirecao!=1) Snake.direcao = 3; // SETA PRA ESQUERDA
				e.preventDefault();
				break;
		}
	}
}



window.onload = Canvas._init;
document.onkeydown = Jogo._controles;