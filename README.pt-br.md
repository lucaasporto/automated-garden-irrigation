<div align="right">
  🇺🇸 <a href="README.md">English</a> | 🇧🇷 <strong>Português</strong>
</div>

# 🌱 Sistema de Irrigação Automatizada para Hortas

Sistema embarcado para monitoramento e irrigação automática de uma horta utilizando **ESP8266**, sensores ambientais e comunicação via **Wi-Fi** com a plataforma **Blynk**, permitindo monitoramento e controle remoto em tempo real.

---

# 📖 Sobre o Projeto

Este projeto foi desenvolvido durante a disciplina **Projeto Integrador I (DEC0013)** da **Universidade Federal de Santa Catarina (UFSC)**.

### Professores Orientadores

- Dr. Jim Lau
- Dra. Olga Yevseyeva
- Dra. Andréa Sabedra Bordin

### Autores

- Lucas Porto Ribeiro
- João Victor Pavan
- Nélio Pagani Neto

**Semestre:** 2023/2

---

# 🎯 Motivação

A irrigação manual de hortas depende da disponibilidade e atenção do responsável. Em muitas situações, o esquecimento da rega ou a irrigação inadequada pode comprometer o desenvolvimento das plantas.

Este projeto foi desenvolvido para automatizar esse processo, monitorando continuamente as condições da horta e realizando a irrigação apenas quando necessário. Além disso, o sistema permite que todas as informações sejam acompanhadas remotamente por meio de um aplicativo.

Os principais objetivos são:

- Automatizar a irrigação da horta;
- Evitar o esquecimento da rega;
- Melhorar o acompanhamento das condições ambientais;
- Reduzir desperdício de água;
- Facilitar o cultivo de plantas.

---

# 📋 Descrição Geral do Sistema

O sistema consiste em uma horta automatizada capaz de monitorar:

- Temperatura do ambiente;
- Umidade relativa do ar;
- Umidade do solo.

Todas as informações são coletadas pelo **ESP8266**, que realiza o processamento dos dados e comunica-se via **Wi-Fi** com a plataforma **Blynk**, permitindo que o usuário acompanhe a horta pelo celular ou computador.

Além do monitoramento, o sistema pode acionar automaticamente uma bomba d'água por meio de um módulo relé sempre que a umidade do solo atingir um valor mínimo definido pelo usuário.

---

# ⚙️ Funcionalidades

- 🌡️ Monitoramento da temperatura ambiente
- 💧 Monitoramento da umidade do ar
- 🌱 Monitoramento da umidade do solo
- 🚰 Irrigação automática
- 📱 Controle manual pelo aplicativo
- 📊 Histórico das medições
- 🌐 Comunicação via Wi-Fi

---

# ✅ Requisitos Funcionais

- RF01 — Armazenar informações de temperatura, umidade do ar e umidade do solo;
- RF02 — Permitir o acionamento manual da irrigação;
- RF03 — Acionar automaticamente a bomba d'água conforme a umidade do solo;
- RF04 — Permitir que o usuário configure o valor mínimo de umidade para irrigação automática.

---

# 🔒 Requisitos Não Funcionais

- RNF01 — Interface simples e intuitiva;
- RNF02 — Sistema adaptável para diferentes tipos de plantas;
- RNF03 — Acesso por aplicativo mobile e dashboard web;
- RNF04 — Hardware resistente às condições do ambiente de operação.

---

# 📜 Regras de Negócio

- RN01 — Apenas usuários autorizados podem acessar o sistema.
- RN02 — O sistema deve permanecer disponível continuamente.
- RN03 — A irrigação automática somente ocorre quando a umidade do solo estiver abaixo do valor configurado.
- RN04 — O usuário pode iniciar a irrigação manualmente a qualquer momento.

---

# 💻 Firmware

Bibliotecas utilizadas:

- ESP8266WiFi
- BlynkSimpleEsp8266
- DHT
- Adafruit Sensor

O programa é responsável por:

- realizar a leitura dos sensores;
- enviar dados para o aplicativo;
- receber comandos do usuário;
- controlar automaticamente o relé da bomba d'água;
- manter a comunicação Wi-Fi.

---

# 🌐 Comunicação entre os Dispositivos

O funcionamento do sistema ocorre conforme o fluxo abaixo:

1. Os sensores realizam as medições.
2. O ESP8266 processa as informações.
3. Os dados são enviados ao servidor Blynk via Wi-Fi.
4. O aplicativo apresenta as informações ao usuário.
5. O usuário pode enviar comandos de irrigação.
6. O ESP8266 recebe os comandos e controla o relé da bomba.

<p align="center">
<img src="images/communication_diagram.jpg" width="800">
</p>

---

# 👤 Diagrama de Caso de Uso

O sistema possui um único ator principal: o usuário.

Por meio do aplicativo Blynk, o usuário pode:

- visualizar temperatura;
- visualizar umidade do ar;
- visualizar umidade do solo;
- configurar o limite mínimo de umidade;
- ativar ou desativar a irrigação manualmente.

<p align="center">
<img src="images/use_case_diagram.jpg" width="800">
</p>

---

# 🔧 Hardware Utilizado

O sistema foi desenvolvido utilizando:

- ESP8266 NodeMCU
- Sensor DHT11
- Sensor de Umidade do Solo (MH Sensor)
- Módulo Relé
- Bomba d'água
- Fonte de alimentação
- Mangueira de irrigação

### Diagrama do Circuito

<p align="center">
<img src="images/electrical_diagram.jpg" width="800">
</p>

### Protótipo de Hardware

A imagem abaixo apresenta a implementação física do sistema, mostrando a montagem do circuito com o ESP8266, sensores, módulo relé, bomba d'água e demais componentes utilizados durante a validação do projeto.

<p align="center">
<img src="images/hardware_setup.jpg" width="800">
</p>

---

# 📱 Interface do Aplicativo

A interface foi desenvolvida utilizando a plataforma **Blynk**.

Ela permite:

- visualizar temperatura;
- visualizar umidade do ar;
- visualizar umidade do solo;
- acompanhar o histórico das medições;
- ligar ou desligar a irrigação manualmente;
- configurar o limite mínimo de umidade do solo para irrigação automática.

### Interface

<p align="center">
<img src="images/blynk_interface.jpg" width="800">
</p>

---

# 🌿 Horta Utilizada

Durante a validação do projeto foi utilizada uma horta de 35x15cm com 4 alfaces.

A irrigação é realizada por uma mangueira instalada no vaso e alimentada por uma bomba d'água acionada pelo sistema. Paralelamente, os sensores monitoram continuamente a temperatura ambiente, a umidade do ar e a umidade do solo.

### Horta

<p align="center">
<img src="images/garden.jpg" width="800">
</p>

---

# 📂 Estrutura do Projeto

```text
.
├── firmware/
│   └── main.ino
├── docs/
│   └── report.pdf
├── images/
└── README.md

```

---

## 📄 Documentos do projeto

* 📄 **[Relatório](docs/report.pdf)**
* 📊 **[Slides de Apresentação do Projeto](docs/project_presentation.pptx)**
