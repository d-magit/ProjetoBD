 #include <iostream>
 #include <string.h>
 #include "curses.h"
 #include "../Entidades.h"
 #include "controladoresapresentacao.h"

// //--------------------------------------------------------------------------------------------
 void CntrApresentacaoControle::Executar(){

     bool apresentar = true;
     int campo;
     int linha,coluna;
     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

         while(apresentar){
             clear();
             mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                                                 // Imprime nome do campo.
             mvprintw(linha/4 + 2,coluna/4,"%s","1 - Acessar sistema.");                                             // Imprime nome do campo.
             mvprintw(linha/4 + 4,coluna/4,"%s","2 - Cadastrar usuario.");                                             // Imprime nome do campo.
             noecho();
             campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
             echo();


             switch(campo){
                 case 1:
                 int retorno;
                 retorno = cntrApresentacaoAutenticacao->autenticar(& this.usuario);
                 switch(retorno){
                     case 0:
                         while(apresentar){
                             clear();                                                            // Limpa janela.
                             mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                             // Imprime nome do campo.
//                             mvprintw(linha/4 + 2,coluna/4,"%s","1 - Selecionar servicos de participante.");                         // Imprime nome do campo.
//                             mvprintw(linha/4 + 4,coluna/4,"%s","2 - Selecionar servicos relacionados a pecas, sessoes ou salas.");                         // Imprime nome do campo.
//                             mvprintw(linha/4 + 6,coluna/4,"%s","3 - Encerrar sessao.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
//                             noecho();
//                             campo = getch() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.
//                             echo();
//                             switch(campo){
//                                 case 1:
//                                     if(cntrApresentacaoParticipante->executar(matricula))
//                                         apresentar=false;
//                                         break;
//                                 case 2: cntrApresentacaoPSS->executar(matricula);
//                                         break;
//                                 case 3: apresentar = false;
//                                         break;
//                                         }
//                             }
//                             apresentar=true;
//                             break;
//                     case 1:
//                         clear();
//                         mvprintw(linha/4,coluna/4,"%s","Senha incorreta");
//                         getch();
//                         break;
//                     case 2:
//                         clear();
//                         mvprintw(linha/4,coluna/4,"%s","Matricula inexistente");
//                         getch();
//                         break;
//                     default:
//                             clear();                                                                // Limpa janela.
//                             mvprintw(linha/4,coluna/4,"%s","Falha na autenticacao. Digite algo para continuar.");                                // Imprime mensagem.
//                             noecho();                                                               // Desabilita eco.
//                             getch();                                                                // Leitura de caracter digitado.
//                             echo();
//                             break;                                                          // Habilita eco.
//                     }
//                     break;

//                 case 2:
//                     cntrApresentacaoParticipante->cadastrar();
//                     break;

//                 case 3:
//                     cntrApresentacaoPSS->executar();
//                     break;
//                 case 4:
//                     apresentar = false;
//                     break;

//             }



//         }

// }


// //--------------------------------------------------------------------------------------------
// // Autenticacao
// //--------------------------- Private ---------------------------
// //--------------------------- Public ----------------------------
 int CntrApresentacaoControle::autenticar(Usuario *usuario){
     string username
     string senha;
     string email
     int linha,coluna;                                                                           // Dados sobre tamanho da tela.
     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
     echo();                                                                                     // Habilita eco.
     char campo1[80];
     char campo2[80];
     // Solicitar username e senha

     while(true) {
         clear();                                                                                // Limpa janela.
         mvprintw(linha/4,coluna/4,"%s","Digite o Username : ");                                                 // Imprime nome do campo.
         getstr(campo1);                                                                         // L� valor do campo.
         mvprintw(linha/4 + 2,coluna/4,"%s","Digite a senha: ");                                             // Imprime nome do campo.
         getstr(campo2);
        
        usuario->Username = campo1
        usuario->Username = campo1

     // Solicitar autentica��o.
     int resultado = cntrServicoAutenticacao->autenticar(*matricula, senha);

     return resultado;
 }

// //--------------------------------------------------------------------------------------------
// // CntrApresentacaoParticipante
// //--------------------------- Private ---------------------------
// void CntrApresentacaoParticipante::consultarDadosPessoais(const Matricula& matricula){
//     Participante *participante = new Participante;
//     cntrServicoParticipante->visualizarUsuario(matricula,participante);
//     int linha,coluna;                                                                           // Dados sobre tamanho da tela.
//     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
//     clear();
//     mvprintw(linha/8+2,coluna/4,"%s %s","Matricula : ", participante->getMatricula().getValor().c_str());
//     mvprintw(linha/8+4,coluna/4,"%s %s","Nome : ", participante->getNome().getValor().c_str());
//     mvprintw(linha/8+6,coluna/4,"%s %s","Sobrenome : ", participante->getSobrenome().getValor().c_str());
//     mvprintw(linha/8+8,coluna/4,"%s %s","Cargo : ", participante->getCargo().getValor().c_str());
//     mvprintw(linha/8+10,coluna/4,"%s %s","Email : ", participante->getEmail().getValor().c_str());
//     mvprintw(linha/8+12,coluna/4,"%s %s","Telefone : ", participante->getTelefone().getValor().c_str());
//     mvprintw(linha/8+14,coluna/4,"%s %s","Senha : ", participante->getSenha().getValor().c_str());
//     mvprintw(linha/8+16,coluna/4,"%s %s","IdPeca : ", participante->getIdPeca().getValor().c_str());
//     mvprintw(linha/8+18,coluna/4,"%s","Digite algo para continuar");
//     getch();                                                                            // L� caracter digitado.

// }
// void CntrApresentacaoParticipante::editarUsuario(const Matricula& matricula){
//     Participante participante;
//     participante.setMatricula(matricula);
//     char campo1[80];
//     int linha,coluna;                                                                           // Dados sobre tamanho da tela.
//     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
//     Nome nome;
//     Nome sobrenome;
//     Email email;
//     Cargo cargo;
//     Telefone telefone;
//     Senha senha;
//     while(true) {
//         try {
//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Nome : (vazio para não modificar)");
//             getstr(campo1);
//             if(strcmp(campo1, "") != 0){
//                 nome.setValor(campo1);
//                 participante.setNome(nome);
//             }
//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Sobrenome :  (vazio para não modificar)");
//             getstr(campo1);
//             if(strcmp(campo1, "") != 0){
//                 sobrenome.setValor(campo1);
//                 participante.setSobrenome(sobrenome);
//             }

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Email :  (vazio para não modificar)");
//             getstr(campo1);
//             if(strcmp(campo1, "") != 0){
//                 email.setValor(campo1);
//                 participante.setEmail(email);
//             }

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Cargo :  (vazio para não modificar)");
//             getstr(campo1);
//             if(strcmp(campo1, "") != 0){
//                 cargo.setValor(campo1);
//                 participante.setCargo(cargo);
//             }

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite a Senha : (vazio para não modificar) ");
//             getstr(campo1);
//             if(strcmp(campo1, "") != 0){
//                 senha.setValor(campo1);
//                 participante.setSenha(senha);
//             }

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Telefone :  (vazio para não modificar)");
//             getstr(campo1);
//             if(strcmp(campo1, "") != 0){
//                 telefone.setValor(campo1);
//                 participante.setTelefone(telefone);
//             }

//             break;
//         }
//         catch (const invalid_argument &exp) {
//             clear();                                                                            // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
//             noecho();
//             getch();                                                                            // L� caracter digitado.
//             echo();
//             // Tratamento de exce��o
//         }
//     }
//     int resultado;
//     clear();
//     resultado = cntrServicoParticipante->editarUsuario(participante);
//     switch(resultado){
//     case 0:
//         mvprintw(linha/4,coluna/4,"%s","Participante editado com sucesso. Digite algo.");
//         noecho();
//         getch();
//         echo();
//         break;
//     case 1:
//     default:
//         mvprintw(linha/4,coluna/4,"%s","Falha ao editar participante. Digite algo.");
//         noecho();
//         getch();
//         echo();
//         break;
//     }
// }
// void CntrApresentacaoParticipante::excluirUsuario(const Matricula& matricula){
//     int linha,coluna;                                                                           // Dados sobre tamanho da tela.
//     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
//     clear();
//     int resultado = cntrServicoParticipante->excluirUsuario(matricula);
//     switch(resultado){
//         case 0:
//             mvprintw(linha/4,coluna/4,"%s","Participante excluido com sucesso. Digite algo.");
//             noecho();
//             getch();
//             echo();
//             break;
//         case 1:
//         default:
//             mvprintw(linha/4,coluna/4,"%s","Falha ao excluir participante. Digite algo.");
//             noecho();
//             getch();
//             echo();
//         break;
//     }
// }
// void CntrApresentacaoParticipante::cadastrarcomoparticipante(const Matricula& matricula){
//     clear();
//     int linha,coluna;                                                                           // Dados sobre tamanho da tela.
//     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
//     bool apresentar=true;
//     char campo[80];
//     Codigo codigo;
//     while(apresentar){
//         mvprintw(linha/6,coluna/4,"%s","Insira o c�digo da pe�a : ");                             // Imprime nome do campo.
//         getstr(campo);
//         try{
//             codigo.setValor(campo);
//             apresentar =false;
//         }
//         catch(...){
//             clear();
//             mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
//             noecho();
//             getch();                                                                            // L� caracter digitado.
//             echo();
//         }
//     }
//     int resultado = cntrServicoParticipante->cadastrarComoParticipante(matricula,codigo);
//     switch(resultado){
//         case 0:
//             mvprintw(linha/4,coluna/4,"%s","Participante cadastrado em Peca com sucesso. Digite algo.");
//             noecho();
//             getch();
//             echo();
//             break;
//         case 1:
//         default:
//             mvprintw(linha/4,coluna/4,"%s","Falha ao cadastrar participante em Peca. Digite algo.");
//             noecho();
//             getch();
//             echo();
//     }


// }
// //--------------------------- Public ----------------------------
// void CntrApresentacaoParticipante::cadastrar(){
//     Participante participante;
//     char campo1[80];
//     int linha,coluna;                                                                           // Dados sobre tamanho da tela.
//     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
//     Matricula matricula;
//     Nome nome;
//     Nome sobrenome;
//     Email email;
//     Cargo cargo;
//     Telefone telefone;
//     Senha senha;
//     while(true) {
//         try {
//             clear();
//             mvprintw(linha/4,coluna/4,"%s","Digite a Matricula : ");
//             getstr(campo1);
//             matricula.setValor(campo1);

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Nome : ");
//             getstr(campo1);
//             nome.setValor(campo1);

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Sobrenome : ");
//             getstr(campo1);
//             sobrenome.setValor(campo1);

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Email : ");
//             getstr(campo1);
//             email.setValor(campo1);

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Cargo : ");
//             getstr(campo1);
//             cargo.setValor(campo1);

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite a Senha : ");
//             getstr(campo1);
//             senha.setValor(campo1);

//             clear();                                                                                // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Digite o Telefone : ");
//             getstr(campo1);

//             telefone.setValor(campo1);

//             participante.setMatricula(matricula);
//             participante.setNome(nome);
//             participante.setSobrenome(sobrenome);
//             participante.setCargo(cargo);
//             participante.setEmail(email);
//             participante.setSenha(senha);
//             participante.setTelefone(telefone);

//             break;
//         }
//         catch (const invalid_argument &exp) {
//             clear();                                                                            // Limpa janela.
//             mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
//             noecho();
//             getch();                                                                            // L� caracter digitado.
//             echo();
//             // Tratamento de exce��o
//         }
//     }
//     int resultado;
//     clear();
//     resultado = cntrServicoParticipante->cadastrarUsuario(participante);
//     switch(resultado){
//         case 0:
//             mvprintw(linha/4,coluna/4,"%s","Participante cadastrado com sucesso. Digite algo.");
//             noecho();
//             getch();
//             echo();
//             break;
//         case 1:
//             mvprintw(linha/4 -3,coluna/4,"%s","Falha no cadastro. Muito provavelmente ja existe usu�rio com essa matricula. Digite algo.");
//             noecho();
//             getch();
//             echo();
//             break;
//     }
// }
// bool CntrApresentacaoParticipante::executar(const Matricula& matricula){
//     clear();
//     int linha,coluna;                                                                           // Dados sobre tamanho da tela.
//     getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
//     bool apresentar=true;
//     int campo;
//     while(apresentar){
//             clear();
//             mvprintw(linha/6,coluna/4,"%s","Selecione um dos servicos : ");                             // Imprime nome do campo.
//             mvprintw(linha/6 + 2,coluna/4,"%s","1 - Ver dados de usuario.");                         // Imprime nome do campo.
//             mvprintw(linha/6 + 4,coluna/4,"%s","2 - Editar dados de usuario.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
//             mvprintw(linha/6 + 6,coluna/4,"%s","3 - Excluir usuario.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
//             mvprintw(linha/6 + 8,coluna/4,"%s","4 - Cadastrar usuario como participante de Peca.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
//             mvprintw(linha/6 + 10,coluna/4,"%s","5 - Retornar.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
//             campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
//             switch(campo){
//                 case 1:
//                     consultarDadosPessoais(matricula);
//                     break;
//                 case 2:
//                     editarUsuario(matricula);
//                     break;
//                 case 3:
//                     excluirUsuario(matricula);
//                     return true;
//                     break;
//                 case 4:
//                     cadastrarcomoparticipante(matricula);
//                     break;
//                 case 5:
//                     return false;
//                     break;
//             }


//     }
//     return false;
// }

