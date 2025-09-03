# Gestão de Eventos (C)

Programa em C para gestão de eventos, permitindo criar, listar, editar e remover eventos;  
criar, inscrever e remover inscritos de eventos;  
mostrar estatísticas da aplicação;  
mostrar bilhetes.

**Nota:** os dados são mantidos apenas durante a execução, não há persistência em ficheiros ou base de dados.

## Tecnologias
- Linguagem: C
- IDE: VS Code
- Compilador: GCC/Clang

## Funcionalidades
- Criar evento (nome, data, local)
- Listar todos os eventos
- Editar evento existente
- Remover evento
- Inscrever participante em evento
- Remover participante de evento
- Mostrar estatísticas da aplicação
- Mostrar bilhetes
- Futuro: persistência de dados em ficheiro

## Estrutura do projeto
eventos-c/
├── src/ # ficheiros .c e .h
├── README.md
└── .gitignore


## Como compilar e executar
No terminal, dentro da pasta do projeto:

```bash
gcc -Wall -O2 -o eventos src/*.c
./eventos

## Autor
Teu Nome — gui24214
