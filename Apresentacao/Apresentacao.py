import pygame
class Apresentacao:
    def __init__(self, business):
        print("Presentation: Initializing!")
        pygame.init()
        self.white = (255,255,255)
        self.black = (0,0,0)
        self.X = 500
        self.Y = 500
        self.textbuffer =""
        self.__business = business
        self.display_surface = pygame.display.set_mode((self.X,self.Y))
        self.font = pygame.font.Font('resources/ostrich-regular.ttf',32)
        self.exec()

    def exec(self):
        while True:
            match self.TelaInicial():
                case 1:
                    login = self.TelaInput(["Insira Usuario", "Insira Senha"])
                    user = self.__business.Authenticate(login)
                    if user != None:
                        self.ProcessParticipant(user['Nome'])
                    else:
                        self.TelaInput(["Erro na Autenticacao. Aperte Enter"])
                case 2: 
                    cadastro = self.TelaInput(["Insira Usuario", "Insira Senha", "Insira Email"])
                    if self.__business.CreateUser(cadastro):
                        self.TelaInput(["Cadastro bem sucedido. Aperte Enter"])
                    else:
                        self.TelaInput(["Erro no Cadastro. Aperte Enter"])

    def ProcessParticipant(self, username):
        while True:
            match self.TelaParticipante():
                #case 1,2,3 listagem
                case 0:
                    #listarpoliticos
                    pass
                case 1:
                    #listarpaises
                    pass
                case 2:
                    evaluations = self.__business.ListUserEvaluations(username)
                    self.TelaListagem(evaluations)
                case 3:
                    #mediasalarial
                    pass
                case 4:
                    criaravaliacao = [username]
                    criaravaliacao += self.TelaInput(["Insira o ID do Politico","Insira a Nota", "Insira seu Comentario"])
                    if self.__business.CreateEvaluation(criaravaliacao):
                        self.TelaInput(["Avaliacao bem sucedido. Aperte Enter"])
                    else:
                        self.TelaInput(["Erro na Avaliacao. Aperte Enter"])
                case 5:
                    editaravaliacao = self.TelaInput(["Insira o ID da Avaliacao", "Insira a nova Nota", "Insira novo Comentario"])
                    if self.__business.UpdateEvaluation(editaravaliacao):
                        self.TelaInput(["Edicao da Avaliacao bem sucedida. Aperte Enter"])
                    else:
                        self.TelaInput(["Erro na edicao da Avaliacao. Aperte Enter"])
                case 6:
                    excluiravaliacao = self.TelaInput(["Insira o ID da Avaliacao"])
                    if self.__business.DeleteEvaluation(excluiravaliacao):
                        self.TelaInput(["Remoção da Avaliacao bem sucedida. Aperte Enter"])
                    else:
                        self.TelaInput(["Erro na remoção da Avaliacao. Aperte Enter"])
                case 7:
                    break
                case 8:
                    editarusuario = [username]
                    editarusuario += self.TelaInput(["Insira sua nova senha", "Insira seu novo email"])
                    self.__business.UpdateUser(editarusuario)
                case 9:
                    self.__business.DeleteUser(username)
                    self.TelaInput(["Usuario deletado. Aperte Enter"])
                    break


    def TelaInicial(self):
        text1 = self.BlipText("Login", self.X//2,self.Y//3)
        text2 = self.BlipText("Cadastro", self.X//2,self.Y//2)
        image = pygame.image.load("resources/symbol.jpg")
        image = pygame.transform.scale(image,(100,100))

        while True:
            self.display_surface.fill(self.white)
            self.display_surface.blit(text1[0],text1[1])
            self.display_surface.blit(text2[0],text2[1])
            self.display_surface.blit(image, (200,300))

            for event in pygame.event.get():
                if self.ClickText(text1,event):
                    return 1
                if self.ClickText(text2,event):
                    return 2

                self.CheckQuit(event)

            pygame.display.update()

    def TelaParticipante(self):
        texts = [
            self.BlipText("Listar Politicos", self.X//4,self.Y//6),
            self.BlipText("Listar Paises", self.X//4,self.Y//4),
            self.BlipText("Listar Avaliacoes", self.X//4,self.Y//3),
            self.BlipText("Media Salarial", self.X//4,self.Y//2),
            self.BlipText("Criar Avaliacao", self.X*(2/3),self.Y//6),
            self.BlipText("Editar Avaliacao", self.X*(2/3),self.Y//4),
            self.BlipText("Excluir Avaliacao", self.X*(2/3),self.Y//3),
            self.BlipText("Sair", self.X*(2/3),self.Y//2),
            self.BlipText("Editar Usuario", self.X//4,self.Y//2 + 40),
            self.BlipText("Excluir Usuario", self.X*(2/3),self.Y//2 + 40)
        ]
        image = pygame.image.load("resources/oda.png")
        image = pygame.transform.scale(image,(105,102))

        while True:
            self.display_surface.fill(self.white)
            for text in texts:
                self.display_surface.blit(text[0],text[1])
            self.display_surface.blit(image, (200,350))

            for event in pygame.event.get():
                for i in range(len(texts)):
                    if self.ClickText(texts[i],event):
                        return i
                
                self.CheckQuit(event)

            pygame.display.update()
    
    def TelaListagem(self,listagem):
        self.font = pygame.font.Font('resources/ostrich-regular.ttf',25)
        texts =[]
        countY = 20
        countX = self.X//3
        enter = self.BlipText("Aperte enter para sair.", self.X//2, self.Y-25)
        for membro in listagem:
            avaliacao = "Usuario '" + membro["Usuario_Nome"] + "' avaliou politico "+ str(membro["Politico_ID"]) + " com nota "+str(membro["Nota"])
            comentario = "Comentario: " + membro["Comentario"]
            texts.append(self.BlipText(avaliacao, countX, countY))
            countY +=25
            self.font = pygame.font.Font('resources/playfair.otf',20)
            texts.append(self.BlipText(comentario, countX, countY))
            self.font = pygame.font.Font('resources/ostrich-regular.ttf',25)
            countY +=30

        while True:
            self.display_surface.fill(self.white)
            for texto in texts:
                self.display_surface.blit(texto[0],texto[1])
                for event in pygame.event.get():
                    if self.ReadText(event):
                        self.textbuffer =""
                        self.font = pygame.font.Font('resources/ostrich-regular.ttf',32)
                        return True
                    self.CheckQuit(event)
            self.display_surface.blit(enter[0],enter[1])
            pygame.display.update()

    def TelaInput(self,texts):
        listainputs = []
        for insert in texts:
            textn = self.BlipText(insert, self.X//2,self.Y//3)
            display = True
            while display:
                self.display_surface.fill(self.white)
                self.display_surface.blit(textn[0],textn[1] )
                for event in pygame.event.get():
                    if self.ReadText(event):
                        listainputs.append(self.textbuffer)
                        self.textbuffer =""
                        display = False
                    self.CheckQuit(event)
    
                self.font = pygame.font.Font('resources/playfair.otf',32)
                textinput = self.BlipText(self.textbuffer,self.X//2,self.Y//2)
                self.font = pygame.font.Font('resources/ostrich-regular.ttf',32)
                self.display_surface.blit(textinput[0],textinput[1])
                pygame.display.update()
        return listainputs

    def BlipText(self,string,x,y):
        text = self.font.render(string,True,self.black)
        textrect = text.get_rect()
        textrect.center = (x,y)
        return (text,textrect)

    def ReadText(self,event):
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RETURN:
                return True
            elif event.key == pygame.K_BACKSPACE:
                self.textbuffer = self.textbuffer[:-1]
            else:
                self.textbuffer+= event.unicode
        return False
    

    def ClickText(self,text,event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            if text[1].collidepoint(event.pos):
                return True

    def CheckQuit(self,event):
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()




        







    
