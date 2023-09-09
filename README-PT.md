# SONIC CD RANDOMIZER TRACKER

Um tracker para Sonic CD Randomizer, desenvolvido em C++, especificamente para o modo "Segments".

Dentre todos os modos disponíveis no Randomizer, o modo "Segments" é, para mim, o modo mais interessante ao oferecer um bom desafio e um fácil rastreio do progresso do jogador pelo randomizer. A maioria dos modos esbarra no problema de ser muito difícil rastrear onde o jogador se encontra no randomizer ou quem está na liderança em um contexto de corrida. Para piorar, há a possibilidade de um jogador, subitamente, alcançar o final do randomizer via time travel direto para os créditos, estragando a diversão do randomizer como um todo.

## Segments?

Neste modo do Randomizer, o jogo define sete zonas (**segmentos**) contendo 8 fases, além de uma última fase com um Chefão. As 8 primeiras fases podem ser quaisquer Atos 1 e 2 e suas respectivas Time Zones (`Past`, `Present`, `Good Future` e `Bad Future`). Chefões pode ser qualquer Ato 3 no Good Future ou Bad Future. No final, o jogador enfrentará 7 dos 14 possíveis Chefões.

Completar uma fase no segmento leva o jogador para a próxima fase do segmento. O chefão do segmento pode ser acessado ao completar as 8 fases em ordem (referenciado aqui como a **Rota Principal** do segmento). Apesar de ser a rota mais garantida de se chegar ao final do segmento, também é a rota mais lenta.Alternativamente, o jogador pode performar um **Time Travel** (acionando a placa de `Past` ou `Future`). O Time Travel levará o jogador para uma das fases do segmento atual. Por um lado, o jogador pode avançar mais rápido pelo segmento, pulando fases no processo. Por outro lado, o jogador pode ser levado para a fase em que ele se encontra no momento ou, no pior caso, retroceder pelo segmento. O Time Travel nunca levará o jogador direto para o Chefão do segmento.

A cada segmento também está associado uma das sete **Time Stones**. Ao completar o Special Stage do segmento, e recuperar a respectiva Time Stone, o jogador garante o Good Future do segmento (se houver fases com Bad Future, o jogador ainda acessará estas fases normalmente). Ao garantir o Good Future, o jogador pode acessar um chefão alternativo para o segmento.

## Como o tracker funciona

O programa pedirá que o usuário informe como a fase foi concluída (por Signpost, por Time Travel para Past ou Future), seguido da fase acessada e seu respectivo ato, seguido da Time Zone em que o jogador se encontra.

O tracker tentará montar um "mapa" do segmento atual, informando quais fases podem ser acessadas a partir da posição atual do jogador após finalizar a fase ou performar um time travel.

O tracker também possui um mecanismo de integração com o OBS para aqueles que quiserem exibir informações em stream o seu progresso no randomizer.

## Estado atual do programa

O tracker é funcional, porém ainda precisa de polimento.
- Entrada é feita por mnemonicos ("siglas" de poucos caracteres para cada função). Esta entrada não é a mais amigável para o usuário comum.
- O fato do programa rodar em terminal (e não haver um executável "tradicional") torna o programa ainda mais difícil de se interagir.
- Não é possível corrigir entradas no tracker. Se o usuário digitar a informação errada, será salva no tracker incorretamente.
- A integração do OBS precisa ser refeita. A lógica que envisionei para o tracker é errônea, pois considera que o jogador não "repetirá" chefões, o que é incorreto (por exemplo, o jogador pode enfrentar o chefão de Tidal Tempest no Bad Future e, em seguida, enfrentar o mesmo chefão de Tidal Tempest, só que no Good Future)
- O tracker não consegue montar o segmento, apenas listando as fases na ordem que foram visitadas pelo jogador, e não na ordem que se encontram no randomizer. Este é o meu maior desafio ao montar o tracker.
- Minha meta final é montar um tracker com uma interface gráfica, de mais fácil uso para o usuário e de mais fácil compreensão.
- Atualmente, o Randomizer permite a opção de gerar um *spoiler log* gráfico. Meu desejo é montar um tracker com uma visualização gráfica que monte o segmento a medida que o jogador joga e preenche as informações

## Requisitos

Este projeto foi gerado com [Angular CLI](https://github.com/angular/angular-cli) versão 16.1.5.

### Servidor de Desenvolvimento

Para iniciar um servidor de desenvolvimento, execute `ng serve`. Visite `http://localhost:4200/`. A aplicação deverá recarregar automaticamente em caso de alterações nos arquivos do código-fonte.

### Geração de Código

Para gerar novos componentes, execute `ng generate component component-name`. Você também pode executar `ng generate directive|pipe|service|class|guard|interface|enum|module`.

### Construindo o projeto

Para construir o projeto, execute `ng build`. Os artefatos do projeto serão armazenados na pasta `dist/`.

### Executando testes unitários

Para rodar testes unitários, execute `ng test`. Testes unitários são executados via [Karma](https://karma-runner.github.io).

### Executando testes ponta-a-ponta

Para executar testes ponta-a-ponta usando uma plataforma de sua escolha, execute `ng e2e`. Para usar este comando, primeiramente você precisa adicionar um pacote que implemente capacidades de teste ponta-a-ponta.

### Ajuda

Se você precisa de mais ajuda referente ao Angular CLI, execute `ng help`. Você também pode visitar a página [Angular CLI Overview and Command Reference](https://angular.io/cli) *(em Inglês)*.
