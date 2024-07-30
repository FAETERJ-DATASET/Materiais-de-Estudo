# Dicas para você que fará 5SBD

### Parte 1
Na 1° parte da disciplina, você verá sobre Procedures, recomendo pesquisar como implementa e o que é. Resumindo, é uma função dentro do SQL.
O foco do professor é criar um sistema legado, assim como era feito antes das ORM, com a lógica do negócio no Banco de dados (Já viu o caos né?).

### Parte 2
Na 2° parte da disciplina, você verá o professor tendo como foco a apresentação da linguagem C#, usando o .NET como um modelo de exemplo, para explicar como funciona uma ORM e sua integração com o banco.

De forma geral, a 2° parte é mais um showcase do que fundamentos em si, você pode usar a tecnologia que quiser, eu utilizei Laravel(PHP) por exemplo, junto do MySQL. O André usa .NET(C#) com SQL Server.

### Avaliação e Atividades (passível a mudanças)
Na prática, você irá ter que criar bases ETL(como CSV) para importar, veja o exemplo em: [arquivo de exemplo](ExemploCarga.csv)

E a partir disso irá importar no seu banco de dados numa tabela temporária que por consequência, deve alimentar as tabelas reais.

A avaliação costuma ser um minimundo pedindo isso, você pode ver o exemplo em: [AV1](Minimundo-5SBD-2024-1-BazarMarkeplace.pdf)

A AV2 é mais pessoal e complexa, é basicamente a mesma coisa da AV1, porém numa linguagem de programação, eu criei algo complexo usando Agendador de tarefas(CRONJOB). Está disponível o meu repositório para referência:
<https://github.com/AdrielCavalcante/5SBD>
*não recomendo pegar minhas avaliações como entrega, pois você terá que apresentar o sistema nos mínimos detalhes, **recomendo** que use apenas como referência >:)*