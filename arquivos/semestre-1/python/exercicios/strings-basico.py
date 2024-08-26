# 1) Faça um programa que lê uma string de no máximo 20 caracteres
# e no final imprime quantas letras ‘a’ tem essa string
receberString = input("Digite uma string de até 20 caracteres: ")
contador = 0

while (len(receberString) > 20):
    receberString = input("Reescreva a string, máximo de 20 caracteres excedido: ")

for i in range(len(receberString)):
    if receberString[i] == "a" or receberString[i] == "A":
        contador+= 1

print(f"A string de tamanho {len(receberString)} possui {contador} caracteres da letra A.")



# 2) Faça um programa que leia o nome e sobrenome de uma pessoa o programa deve escrever o nome e o sobrenome numa única
# string. Deverá ser impresso, a nova string, o tamanho dela a primeira e a última letra da string
nome = input("Nome: ")
sobrenome = input("Sobrenome: ")

nomeCompleto = nome + " " + sobrenome

print(f"O nome completo é: {nomeCompleto}.")
print(f"Possui {len(nomeCompleto)} caracteres.")
print(f"Primeiro caractere: {nomeCompleto[0]}, Último caractere: {nomeCompleto[len(nomeCompleto) - 1]}")



# 3) Faça um programa que receba do usuário uma string. O
# programa imprime a string sem suas vogais.
string = input("Insira a string: ").lower()
print("String sem vogais: ", end = '')

for i in range(len(string)):
    if string[i] != "a" and string[i] != "e" and string[i] != "i" and string[i] != "o" and string[i] != "u":
        print(string[i], end = '')



# 4) Ler uma frase e contar quantos caracteres são espaços em brancos
string = input("Digitar a string: ")
contagemPorMetodo = string.count(" ")

# Ou por lógica repetitiva
contagemPorRepeticao = 0
for i in range(len(string)):
    if string[i] == " ":
        contagemPorRepeticao += 1

print(f"Espaços totais: {contagemPorMetodo}")
print(f"Espaços totais: {contagemPorRepeticao}")
