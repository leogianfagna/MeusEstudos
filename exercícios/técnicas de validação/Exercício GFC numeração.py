0 resultado = 0
0 n2 = 0
0 op = ""

1 while True:
    2 print("OP: ", op, "   RESULTADO: ", resultado, "   N2: ", n2)
    2 d = input("> ")
    3 if (d == "+") or (d == "-") or (d == "*") or (d == "/"):
        4 if op != "":
            5 if op == "+":
                6 resultado = resultado + n2
                6 op = d
            7 elif op == "-":
                8 resultado = resultado - n2
                8 op = d
            9 elif op == "*":
                10 resultado = resultado * n2
                10 op = d
            11 elif op == "/":
                12 if n2 != 0:
                    13 resultado = resultado / n2
                    13 op = d
                else:
                    14 resultado = "ERRO"
                    15 op = ""
            15 n2 = resultado
            15 print(": ", resultado)
        else:
            16 op = d
    else:
        17 if d == "=":
            18 if op == "+":
                19 resultado = resultado + n2
                19 op = ""
            20 if op == "-":
                21 resultado = resultado - n2
                21 op = ""
            22 if op == "*":
                23 resultado = resultado * n2
                23 op = ""
            24 if op == "/":
                25 if n2 != 0:
                    26 resultado = resultado / n2
                    26 op = d
                else:
                    27 resultado = "ERRO"
                    27 op = ""
            28 n2 = resultado
            28 print(": ", resultado)
        else:
            29 if (d == "C") or (d == "CLEAR"):
                30 print("..... CLEAR")
                30 resultado = 0
                30 op = ""
                30 n2 = 0
            else:
                31 resultado = n2
                31 n2 = float(d)
