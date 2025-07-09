![image](https://github.com/user-attachments/assets/9de95191-c3fe-4afe-bdf8-e709de7120fa)
> Esta imagem foi gerada por IA

# Sonic BoomBa: Batalha no Espaço 🚀

> Este repositório contém o Trabalho Final da disciplina INF01047 (Fundamentos de Computação Gráfica) da UFRGS, desenvolvido por Eduardo Veiga Ferreira e Vicente Tolentino Isatto.

## Sumario
1. [Descrição](#descrição)
2. [Demonstração](#demonstração)
3. [Manual de Uso](#manual-de-uso)
4. [Instruções de Compilação](#instruções-de-compilação)
5. [Contribuições](#contribuições)
6. [Uso de Ferramentas de IA](#uso-de-ferramentas-de-ia)
7. [Tecnologias Utilizadas](#tecnologias-utilizadas)

---

## Descrição
**Sonic BoomBa** é uma aplicação não-trivial que implementa os conceitos abordados no curso de Fundamentos de Computação Gráfica. O objetivo é simular uma batalha espacial entre Sonic, o personagem principal, e seu inimigo Robotnik. Lançando anéis, o Sonic pode derrotar as réplicas do Robotnik e, ao vencer o jogo, a aplicação se encerra.

O projeto foi gerenciado utilizando um fluxo de trabalho baseado em *Feature Branches*, onde novas funcionalidades foram desenvolvidas em paralelo e integradas de forma incremental.

## Demonstração
![sonic_boomba2](https://github.com/user-attachments/assets/172efac6-6d69-4e74-9486-67f7b4f1717e)

## Manual de Uso

#### Controles
| Tecla(s) | Ação |
| :--- | :--- |
| `W`, `A`, `S`, `D` | Movimentação do personagem (frente, esquerda, trás, direita). |
| `Mouse` | Controla a direção da câmera. |
| `Barra de Espaço` | Lança um projétil ("ring"). |
| `Z` | Alterna entre a câmera livre e a câmera que segue o personagem (look-at).|

#### Execução Rápida (via Makefile)
Para compilar e executar o projeto de forma simples em um ambiente Linux configurado, navegue até o diretório raiz e use os comandos:
```bash
# Compila o projeto
make

# Executa o jogo
make run 
```

---

## Instruções de Compilação
A aplicação foi desenvolvida em C++ com OpenGL e é compatível com ambientes **Linux** e **Windows**.

<details>
<summary><b>Clique para ver as instruções para Windows</b></summary>

Para compilar e executar este projeto no Windows, você possui duas
opções para compilação:

--- Windows com Code::Blocks
-------------------------------------------
Baixe a IDE Code::Blocks em http://codeblocks.org/ e abra o arquivo
"Laboratorio_X.cbp".

**ATENÇÃO**: os "Build targets" padrões (Debug e Release) estão configurados
para Code::Blocks versão 20.03 ou superior, que utiliza MinGW 64-bits. Se você
estiver utilizando versões mais antigas do Code::Blocks (17.12 ou anteriores)
você precisa alterar o "Build target" para "Debug (CBlocks 17.12 32-bit)" ou
"Release (CBlocks 17.12 32-bit)" antes de compilar o projeto.

--- Windows com VSCode (Visual Studio Code)
-------------------------------------------
1) Instale o VSCode seguindo as instruções em https://code.visualstudio.com/ .

2) Instale o compilador GCC no Windows seguindo as instruções em
https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain .

Alternativamente, se você já possui o Code::Blocks instalado no seu PC
(versão que inclui o MinGW), você pode utilizar o GCC que vem com esta
instalação no passo 5.

3) Instale o CMake seguindo as instruções em https://cmake.org/download/ .
Alternativamente, você pode utilizar algum package manager do
Windows para fazer esta instalação, como https://chocolatey.org/ .

4) Instale as extensões "ms-vscode.cpptools" e "ms-vscode.cmake-tools"
no VSCode. Se você abrir o diretório deste projeto no VSCode,
automaticamente será sugerida a instalação destas extensões (pois
estão listadas no arquivo ".vscode/extensions.json").

5) Abra as configurações da extensão cmake-tools (Ctrl-Shift-P e
busque por "CMake: Open CMake Tools Extension Settings"), e adicione o
caminho de instalação do GCC na opção de configuração "additionalCompilerSearchDirs".

Por exemplo, se você quiser utilizar o compilador MinGW que vem junto
com o Code::Blocks, pode preencher o diretório como
"C:\Program Files\CodeBlocks\MinGW\bin" (verifique se este é o local
de instalação do seu Code::Blocks).

6) Clique no botão de "Play" na barra inferior do VSCode para compilar
e executar o projeto. Na primeira compilação, a extensão do CMake para
o VSCode irá perguntar qual compilador você quer utilizar. Selecione
da lista o compilador GCC que você instalou com o MSYS/MinGW.

Veja mais instruções de uso do CMake no VSCode em:

https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/README.md

</details>

<details>
<summary><b>Clique para ver as instruções para Linux</b></summary>

Para compilar e executar este projeto no Linux, primeiro você precisa instalar
as bibliotecas necessárias. Para tanto, execute o comando abaixo em um terminal.
Esse é normalmente suficiente em uma instalação de Linux Ubuntu:

    sudo apt-get install build-essential make libx11-dev libxrandr-dev \
                         libxinerama-dev libxcursor-dev libxcb1-dev libxext-dev \
                         libxrender-dev libxfixes-dev libxau-dev libxdmcp-dev

Se você usa Linux Mint, talvez seja necessário instalar mais algumas bibliotecas:

    sudo apt-get install libmesa-dev libxxf86vm-dev

Após a instalação das bibliotecas acima, você possui várias opções para compilação:

--- Linux com Makefile
-------------------------------------------
Abra um terminal, navegue até a pasta "Laboratorio_0X_Codigo_Fonte", e execute
o comando "make" para compilar. Para executar o código compilado, execute o
comando "make run".

--- Linux com CMake
-------------------------------------------
Abra um terminal, navegue até a pasta "Laboratorio_0X_Codigo_Fonte", e execute
os seguintes comandos:

    mkdir build  # Cria diretório de build
    cd build     # Entra no diretório
    cmake ..     # Realiza a configuração do projeto com o CMake
    make         # Realiza a compilação
    make run     # Executa o código compilado

--- Linux com VSCode
-------------------------------------------

1) Instale o VSCode seguindo as instruções em https://code.visualstudio.com/ .

2) Instale as extensões "ms-vscode.cpptools" e "ms-vscode.cmake-tools"
no VSCode. Se você abrir o diretório deste projeto no VSCode,
automaticamente será sugerida a instalação destas extensões (pois
estão listadas no arquivo ".vscode/extensions.json").

3) Clique no botão de "Play" na barra inferior do VSCode para compilar
e executar o projeto. Na primeira compilação, a extensão do CMake para
o VSCode irá perguntar qual compilador você quer utilizar. Selecione
da lista o compilador que você deseja utilizar.

Veja mais instruções de uso do CMake no VSCode em:

https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/README.md

--- Linux com Code::Blocks
-------------------------------------------
Instale a IDE Code::Blocks (versão Linux em http://codeblocks.org/), abra o
arquivo "Laboratorio_X.cbp", e modifique o "Build target" de "Debug" para "Linux".
</details>

## Contribuições
O trabalho foi desenvolvido em dupla, com colaboração em todas as etapas, mas com os seguintes focos de responsabilidade para organização do desenvolvimento:

#### Eduardo Veiga Ferreira
* **Foco principal:** Animação, câmera, texturas e câmera em primeira pessoa.
* Implementou a estrutura base de iluminação (Difusa, Blinn-Phong), interpolação (Phong, Gouraud) e o sistema de animação por tempo.

#### Vicente Tolentino Isatto
* **Foco principal:** Curvas de Bézier, perseguição de inimigos, projéteis e câmera em primeira pessoa.
* Implementou a lógica de movimentação dos inimigos, o sistema de projéteis e os testes de colisão.

## Uso de Ferramentas de IA
Para o desenvolvimento do trabalho, foram utilizadas ferramentas de IA generativa, como **GitHub Copilot**, **Google Gemini** e **DeepSeek Coder**, como auxiliares de programação.

O desenvolvimento foi iniciado a partir dos códigos desenvolvidos nos laboratórios da disciplina, de forma que tivéssemos um compilado funcional de todas as funcionalidades desenvolvidas em aula. Durante o desenvolvimento, foram exercitados de maneira prática os conceitos vistos em aula, como aplicação de texturas, animações, câmeras, etc.

Por já estarmos construindo partes significativas do trabalho durante o semestre, o maior desafio esteve em compilar tudo isso de maneira concisa, organizada e funcional, além de buscar o desenvolvimento de funcionalidades não trabalhadas de forma extensiva. Foi justamente nesse quesito que a utilização de inteligências artificiais generativas se mostrou útil. O uso dessas ferramentas, no entanto, não foi muito além de uma ferramenta auxiliar, uma vez que não conseguem abstrair a estrutura de código e a lógica aplicadas no desenvolvimento para gerar códigos que sejam funcionais dentro da aplicação.

## Tecnologias Utilizadas
* **Linguagem:** C++
* **API Gráfica:** OpenGL 3.3
* **Bibliotecas:**
  * GLAD (para carregamento de funções do OpenGL)
  * GLFW (para criação de janelas e gerenciamento de input)
  * GLM (para matemática de vetores e matrizes)
  * tinyobjloader (para carregar modelos `.obj`)
  * stb_image (para carregar imagens de textura)
