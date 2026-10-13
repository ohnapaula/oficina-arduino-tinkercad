# Oficina de Arduino + Tinkercad

Repositório com os códigos-fonte, esquemáticos e diagramas visuais dos projetos desenvolvidos na oficina prática de **Arduino com Tinkercad**.

---

## Documentação e Links Úteis

- **[Apresentação no Canva](https://canva.link/oficina-arduino-tinkercad-1-1)**: Slides teóricos e material de apoio visual da oficina.
- **[Documentação Oficial do Arduino](https://docs.arduino.cc/)**: Guia completo de sintaxe, funções, bibliotecas e referências de hardware.
- **[Tinkercad](https://www.tinkercad.com/)**: plataforma gratuita e online desenvolvida pela Autodesk voltada para modelagem 3D, simulação de circuitos eletrônicos e introdução à programação.

---

## Padronização de Pastas e Arquivos

Cada projeto está estruturado em sua própria pasta e contém três arquivos essenciais:

```text
nome_do_projeto/
├── [nome_do_projeto].ino   # Código-fonte em C/C++ para Arduino
├── [nome_do_projeto].brd   # Esquemático/leiaute do circuito (exportado do Tinkercad)
└── [nome_do_projeto].png   # Captura de tela e diagrama visual da simulação
```

---

## Lista de Projetos

| Projeto | Simulação Tinkercad | Descrição | Componentes Principais |
| :--- | :---: | :--- | :--- |
| **[`pisca_led`](./pisca_led)** | [🔗 Acessar Simulação](https://www.tinkercad.com/things/gsv7h2udHFk-piscaled?sharecode=LgL-KwVCrwRigp7unNurzpXDBrBiFQrRyW0ySiGWyqU) | Alterna um LED entre ligado e desligado a cada 1 segundo (Blink). | Arduino Uno, LED, Resistor 330Ω, Protoboard |
| **[`entrada_digital`](./entrada_digital)** | [🔗 Acessar Simulação](https://www.tinkercad.com/things/1GKuLETC8yd-entradadigital?sharecode=YpC_Nst5_wWTffTO9MA6riYy8Iqzvh9zJBErK_50CpE) | Leitura do estado lógico de um botão (Push Button) para controlar um atuador. | Arduino Uno, Push Button, LED, Resistores (10kΩ e 330Ω), Protoboard |
| **[`entrada_analogica`](./entrada_analogica)** | [🔗 Acessar Simulação](https://www.tinkercad.com/things/8VVaVvaPjP9-entradaanalogica?sharecode=AnCA1gUZ7WSjwHueOLFo9Jl_zkAF1068Ve6zGRAzgZo) | Leitura contínua de valores analógicos (0 a 1023) usando potenciômetro. | Arduino Uno, Potenciômetro 10kΩ, LED, Resistor 330Ω, Protoboard |
| **[`estacao_meteorologica`](./estacao_meteorologica)** | [🔗 Acessar Simulação](https://www.tinkercad.com/things/5db4FmNfRyL-estacaometeorologica?sharecode=mwvbgg-MUAl4IeP3XQqqsV8tr3P3xYe-plnd9Rlcu6A) | Sistema de monitoramento de variáveis ambientais (temperatura e luz). | Arduino Uno, Sensor Temp. (TMP36), LDR, LEDs/Resistores, Protoboard |

---

## Como Utilizar os Projetos no Tinkercad

### Opção 1: Via link direto (Recomendado)
1. Escolha o projeto na tabela acima e clique no link **Acessar Simulação**.
2. No Tinkercad, clique em **Copiar e Tinker** (Copy and Tinker) para salvar uma cópia editável em sua conta.
3. Clique em **Iniciar Simulação**.

### Opção 2: Montagem manual
1. Abra a pasta do projeto desejado neste repositório.
2. Copie o conteúdo do arquivo `.ino`.
3. No [Tinkercad](https://www.tinkercad.com/), crie um novo circuito e monte os componentes conforme a imagem `.png`.
4. Abra o painel de **Código**, mude para o modo **Texto** e cole o código `.ino`.
5. Inicie a simulação.

---

## Guia de Commits Semânticos

Este repositório adota o padrão de **Conventional Commits** para manter o histórico claro e organizado:

- `feat`: Adição de um novo projeto ou funcionalidade.
  - *Exemplo:* `feat(pisca_led): adiciona codigo do circuito pisca led`
- `docs`: Alteração na documentação, README, esquemáticos ou imagens.
  - *Exemplo:* `docs(readme): adiciona links das simulacoes do tinkercad`
- `fix`: Correção de erros no circuito ou bugs no código `.ino`.
  - *Exemplo:* `fix(entrada_digital): corrige resistor de pull-down`
- `refactor`: Melhoria ou reorganização do código sem alterar o funcionamento.
  - *Exemplo:* `refactor(entrada_analogica): renomeia variaveis dos pinos para constantes`
- `chore`: Tarefas de manutenção (ex: `.gitignore`, estrutura de pastas).
  - *Exemplo:* `chore: atualiza estrutura do repositorio`