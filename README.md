# Oficina de Arduino + Tinkercad

Repositório para armazenar os códigos-fonte, esquemáticos e diagramas visuais dos projetos desenvolvidos na oficina prática de Arduino com Tinkercad.

---

## Padronização das pastas

Cada projeto da oficina está organizado em sua própria pasta e contém três arquivos essenciais:

* `[nome_do_projeto].ino`: Código-fonte da aplicação (C/C++ Arduino).
* `[nome_do_projeto].brd`: Arquivo do leiaute/esquemático do circuito (exportado do Tinkercad).
* `[nome_do_projeto].png`: Diagrama visual e captura de tela da simulação do Tinkercad.

---

## Lista de projetos

| Pasta | Nome do Projeto | Descrição Curta | Componentes Principais |
| :--- | :--- | :--- | :--- |
| [`pisca_led`](./pisca_led) | Pisca LED (Blink) | Alterna um LED entre ligado e desligado a cada 1 segundo. | Arduino Uno, LED, Resistor 330Ω |

---

## Como utilizar os projetos no Tinkercad

1. Abra a pasta do projeto desejado.
2. Baixe ou copie o conteúdo do arquivo `.ino`.
3. No [Tinkercad](https://www.tinkercad.com/), crie um novo circuito e insira os componentes indicados na imagem `.png`.
4. Abra a aba **Código**, selecione a opção **Texto** e cole o código `.ino`.
5. Inicie a simulação.

---

## Guia de commits semânticos

Este repositório adota o padrão de **conventional commits**:

* `feat`: Adição de um novo projeto ou funcionalidade no código.
  * *Exemplo:* `feat(pisca_led): adiciona codigo do circuito pisca led`
* `docs`: Alteração de documentação, esquemáticos ou imagens `.png`/`.brd`.
  * *Exemplo:* `docs(readme): adiciona tabela de componentes dos projetos`
* `fix`: Correção de erros no circuito ou bugs no código `.ino`.
  * *Exemplo:* `fix(pisca_led): corrige tempo de delay no loop`
* `chore`: Manutenção de arquivos de configuração, `.gitignore` ou estrutura do repo.
  * *Exemplo:* `chore: inicializa estrutura do repositorio e gitignore`
* `refactor`: Reorganização ou melhoria do código existente sem alterar comportamento.
  * *Exemplo:* `refactor(pisca_led): renomeia variaveis dos pinos para constantes`