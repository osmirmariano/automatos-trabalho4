# teoriaComputacaoAutomatos-TR4

Implementar computacionalmente, em linguagem acordada com o professor, um programa que reconheça a linguagem denotada pela linguagem regular:

(a+b)*a(a+b)(a+b)

Para tanto, você deve projetar o AFN da linguagem, que deverá sem apresentado no programa ou em arquivo pdf. Em seguida, implementar em código-fonte a função de transição do AFN e a função de transição estendida. 

Definimos δ, função de transição estendida, por indução sobre o comprimento da palavra de entrada.

• BASE: δ(q,ε)=q

Isto é, se estamos no estado q e lemos nenhuma entrada, então ainda continuamos no estado q.

• INDUÇÃO: Suponha que w é uma palavra da forma xa, ou seja, a é o último símbolo de w, e x é a palavra que consiste em tudo, menos o último símbolo. Por exemplo, w=1101 é desmembrado em x=110 e a=1. Assim, o passo de indução é:

δ(q,w) = δ(δ(q,x),a)

No entanto, lembre-se que em AFN o retorno de uma função de transição δ é um conjunto de estados. Por isso, considere que 
δ(q,w)={p1,p2,…,pk}.

Assim, ⋃ (𝑝𝑖, 𝑎) = {𝑟1, 𝑟2, … , 𝑟𝑘} 𝑘 𝑖=1

Então,  (q,w)={𝑟1, 𝑟2, … , 𝑟𝑘}. De modo menos formal, calculamos (q,w) calculando primeiro (q,x) e depois seguinto todas as transições de qualquer destes estados que seja rotulada por a.
