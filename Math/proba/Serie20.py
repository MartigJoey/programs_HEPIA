from itertools import product as prod

De = [1,2,3,4,5,6]

def F( nd , YaN , S):
    tirages = prod( De, repeat = nd ) 
    combien_ya , somme_egal, les_deux = [],[],[]
    for k in tirages:
        if sum(k) == S: somme_egal.append(k)
        if YaN in k   : combien_ya.append(k)
        if sum(k) == S and YaN in k: les_deux.append(k)
    return combien_ya, somme_egal, les_deux

def prob_N( N , Y , So):
    Cb , SE , LD = F( N,Y,So )
    CbN , SEN , LDN = len(Cb),len(SE),len(LD)
    prob = LDN/CbN
    phrase = "P({} Dés, Somme = {} | Un dé vaut {}) = {}/{} = {}".format(str(N),str(So),str(Y),str(LDN),str(CbN),str(prob))
    return prob,phrase

def prob_N_mois_un( N , Y , So):
    Cb , SE , LD = F( N-1,Y,So-Y )
    SEN , LDN = len(SE),len(LD)
    prob = SEN/(len(De)**(N-1))
    phrase = "P({} Dés, Somme = {}) = {}/{} = {}".format(str(N-1),str(So-Y),str(SEN),str(len(De)**(N-1)),str(prob))
    return prob,phrase

def un_lancer( ):
    N = input("Combien de dés: ")
    Ya= input("Un dé vaut: ")
    So= input("La somme vaut: ")
    N,Ya,So = int(N),int(Ya),int(So)
    p1,phrase1 = prob_N( N, Ya, So)
    p2,phrase2 = prob_N_mois_un( N , Ya , So)
    return phrase1,phrase2

def tous_les_lancers( ):
    N = input("Combien de dés: ")
    So= input("La somme vaut: ")
    N,So = int(N),int(So)
    probs,phrases = [],[]
    for k in De:
       p1,_ = prob_N( N, k, So)
       p2,_ = prob_N_mois_un( N , k , So)
       if p1 != 0: 
           comp = p2/p1
           probs.append(comp)
           phrases.append("P({} Dés, Somme = {}) / P({} Dés, Somme = {} | Un dé vaut {}) = {}".format(str(N-1),str(So-k),str(N),str(So),str(k),str(comp)))
       else: 
           phrases.append("P({} Dés, Somme = {}) / P({} Dés, Somme = {} | Un dé vaut {}) = 0/0".format(str(N-1),str(So-k),str(N),str(So),str(k)))
           probs.append(0)
    return probs,phrases

def main():
    A = input("Un lancer / tous les lancers ? (a/b) :")
    if A == "a":
         ph1,ph2 = un_lancer()
         print(ph1)
         print(ph2)
    else:
         p , phs = tous_les_lancers()
         for k in phs:
             print(k)


main()
    

