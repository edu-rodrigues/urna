#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;

struct Prefeito
{
    string nome;
    int numero;
    int votos=0;
};

struct Vereador
{
    string nome;
    int numero;
    int votos = 0;
};
stack <Prefeito> prefeitos, tempP;
stack <Vereador> vereadores, tempV;
list <int> brancosV, brancosP;
list <int> nulosV, nulosP;
Prefeito p,p2;
Vereador v,v2;

void PreencheUrna()

{
    bool existe, inseriu;
    char escolha = 'w';
    int tempNum;
    string tempNome;  
   
    while (escolha != 'C' & escolha != 'c')
    {
        system("cls");
        cout << "P para inserir prefeito" << endl;
        cout << "V para inserir vereador" << endl;
        cout << "R para recer os prefeitos e vereadores inseridos" << endl;
        cout << "C para comecar a votacao" << endl;
        cin >> escolha;

        switch (escolha)
        {
        case 'p':
        case'P':
            inseriu = false;
          
            while (inseriu == false)
            {
                existe = false;
                cout << "Insira o nome do prefeito" << endl;
                cin >> tempNome;
                tempNum = 200;
                while(tempNum < 1 || tempNum > 10)
                {
                    cout << "Insira o numero do prefeito, entre 1 e 10" << endl;
                    cin >> tempNum;
                }
                while (!prefeitos.empty())
                {
                    if (tempNum == prefeitos.top().numero)
                    {
                        existe = true;
                    }
                    tempP.push(prefeitos.top());
                    prefeitos.pop();

                }
                while (!tempP.empty())
                {
                    prefeitos.push(tempP.top());
                    tempP.pop();
                }

                if (existe == false)
                {
                    p.nome = tempNome;
                    p.numero = tempNum;
                    prefeitos.push(p);
                    cout << "voce inseriu o prefeito: " << prefeitos.top().nome << " - " << prefeitos.top().numero << endl;
                    inseriu = true;
                }
                else
                {
                    cout << "este prefeito ja exite, tente novamente" << endl;
                }
                system("pause");
            }
            break;
        case 'v':
        case'V':
            inseriu = false;           
            while (inseriu == false)
            {
                existe = false;
                tempNum = 200;
                cout << "Insira o nome do vereador" << endl;
                cin >> tempNome;                
                while (tempNum < 11 || tempNum > 100)
                {
                    cout << "Insira o numero do Vereaor, entre 11 e 100" << endl;
                    cin >> tempNum;
                }


                while (!vereadores.empty())
                {
                    if (tempNum == vereadores.top().numero)
                    {
                        existe = true;
                    }
                    tempV.push(vereadores.top());
                    vereadores.pop();

                }
                while (!tempV.empty())
                {
                    vereadores.push(tempV.top());
                    tempV.pop();
                }

                if (existe == false)
                {
                    v.nome = tempNome;
                    v.numero = tempNum;
                    vereadores.push(v);
                    cout << "voce inseriu o vereador: " << vereadores.top().nome << " - " << vereadores.top().numero << endl;
                    inseriu = true;
                }
                else
                {
                    cout << "este veredaor ja exite, tente novamente" << endl;
                }
                system("pause");
            }
            break;
        case 'r':
            if (!prefeitos.empty())
            {
                cout << "Nome - Numero";
                while (!prefeitos.empty())
                {

                    cout << prefeitos.top().nome << " - " << prefeitos.top().numero << endl;
                    tempP.push(prefeitos.top());
                    prefeitos.pop();

                }
                while (!tempP.empty())
                {
                    prefeitos.push(tempP.top());
                    tempP.pop();
                }
            }
            else
            {
                cout << "lista de prefeitos vazia" << endl;
            }

            if (!vereadores.empty())
            {
                cout << "Nome - Numero" << endl;
                while (!vereadores.empty())
                {

                    cout << vereadores.top().nome << " - " << vereadores.top().numero << endl;
                    tempV.push(vereadores.top());
                    vereadores.pop();

                }
                while (!tempV.empty())
                {
                    vereadores.push(tempV.top());
                    tempV.pop();
                }
            }
            else
            {
                cout << "lista de vereadores vazia" << endl;
            }
            system("pause");
            break;
        case 'c':
        case 'C':
            break;
        default:
            cout << "opcao invalida" << endl;
            break;
        }

    }
}

void Votacao()
{
    queue <int> cpf, c;
    char escolha;
    int temp, numVer, numPref;
    bool existe, fimVotacao = false;
    bool teste, confirmado;
    while (!fimVotacao)
    {
        confirmado = false;
        existe = false;
        system("cls");
        cout << "Insira seu CPF" << endl;
        cin >> temp;
        while (!cpf.empty())
        {
            if (temp == cpf.front())
            {
                cout << "este cpf ja votou" << endl;
                existe = true;
            }
            c.push(cpf.front());
            cpf.pop();
        }
        while (!c.empty())
        {
            cpf.push(c.front());
            c.pop();
        }

        if (!existe)
        {
            cpf.push(temp);
            //                                 VOTO VEREADOR
            while (!confirmado)
            {
                teste = true;
                cout << "Digite 0 para voto em branco" << endl;
                cout << "Digite o numero do verador: " << endl;
                cin >> numVer;
                switch (numVer)
                {
                case 0:
                    cout << "voto em branco confirmado!" << endl;
                    brancosV.push_back(1);
                    confirmado = true;
                    break;
                default:
                    while (teste)
                    {
                        if (numVer == vereadores.top().numero)
                        {
                            cout << "vereador selecionado:" << vereadores.top().nome << " numero: " << vereadores.top().numero;
                            cout << "confirma? S para sim N para nao" << endl;
                            cin >> escolha;
                            switch (escolha)
                            {
                            case 'S':
                            case 's':
                                cout << "voto para vereador completo!" << endl;
                                v.nome = vereadores.top().nome;
                                v.numero = vereadores.top().numero;
                                v.votos = vereadores.top().votos + 1;
                                vereadores.pop();
                                vereadores.push(v);
                                teste = false;
                                confirmado = true;
                                break;

                            case 'n':
                            case 'N':
                                teste = false;
                                break;
                            default:
                                break;
                            }
                        }
                        else
                        {
                            tempV.push(vereadores.top());
                            vereadores.pop();
                        }
                        if (vereadores.empty())
                        {
                            cout << "nenhum vereador com esse numero, caso confirme seu voto sera considerado nulo, S para sim N para nao: " << endl;
                            cin >> escolha;
                            switch (escolha)
                            {
                            case 's':
                            case 'S':
                                cout << "voto nulo confirmado!" << endl;
                                nulosV.push_back(1);
                                teste = false;
                                confirmado = true;
                                break;
                            case 'n':
                            case 'N':
                                teste = false;
                                break;
                            default:
                                break;
                            }
                        }                       
                    }
                    
                    while (!tempV.empty())
                    {
                        vereadores.push(tempV.top());
                        tempV.pop();
                    }
                    break;
                }
            }


            // PREFEITO
            confirmado = false;
            while (!confirmado)
            {
                teste = true;
                cout << "Digite 0 para voto em branco, caso nao:" << endl;
                cout << "digite o numero do prefeito: " << endl;
                cin >> numPref;
                switch (numPref)
                {
                case 0:
                    cout << "voto em branco confirmado!" << endl;
                    brancosP.push_back(1);
                    confirmado = true;
                    break;
                default:
                    while (teste)
                    {
                        if (numPref == prefeitos.top().numero)
                        {
                            cout << "Prefeito selecionado:" << prefeitos.top().nome << " numero: " << prefeitos.top().numero;
                            cout << "confirma? S para sim N para nao" << endl;
                            cin >> escolha;
                            switch (escolha)
                            {
                            case 'S':
                            case 's':
                                cout << "voto para prefeito completo!" << endl;
                                p.nome = prefeitos.top().nome;
                                p.numero = prefeitos.top().numero;
                                p.votos = prefeitos.top().votos + 1;
                                prefeitos.pop();
                                prefeitos.push(p);
                                teste = false;
                                confirmado = true;
                                break;
                            case 'n':
                            case 'N':
                                teste = false;
                                break;
                            default:
                                break;
                            }
                        }
                        else
                        {
                            tempP.push(prefeitos.top());
                            prefeitos.pop();
                        }
                        if (prefeitos.empty())
                        {
                            cout << "nenhum Prefeito com esse numero, caso confirme seu voto sera considerado nulo, S para sim N para nao: " << endl;
                            cin >> escolha;
                            switch (escolha)
                            {
                            case 's':
                            case 'S':
                                cout << "voto nulo confirmado!" << endl;
                                nulosP.push_back(1);
                                teste = false;
                                confirmado = true;
                                break;
                            case 'n':
                            case 'N':
                                teste = false;
                                break;
                            default:
                                break;
                            }
                        }
                       
                    }
                    while (!tempP.empty())
                    {
                        prefeitos.push(tempP.top());
                        tempP.pop();
                    }
                    break;
                }



            }
        }
        cout << "continuar votacao? -S- para sim e -N- para nao" << endl;
        cin >> escolha;
        switch (escolha)
        {
        case 'n':
        case'N':
            fimVotacao = true;
            break;
        default:
            break;
      
        }
       
    }
   
}


    
void Dados()
{
    system("cls");
    cout << "Vereadores: " << endl;
    cout << "Nome - Numero - Votos"<< endl;
    while (!vereadores.empty())
    {
        cout <<vereadores.top().nome << " - " <<vereadores.top().numero <<" - "<<vereadores.top().votos << endl;
        vereadores.pop();       
    }
    cout << "Votos Brancos para vereador: " << brancosV.size()<< endl;
    cout << "Votos Nulos para vereador: " << nulosV.size()<< endl << endl;

    cout << "Prefeitos: " << endl;
    cout << "Nome - Numero - porcentagem" << endl;
    float num = prefeitos.size(), validos = 0;
    while (!prefeitos.empty())
    {
        validos = validos + prefeitos.top().votos;
        tempP.push(prefeitos.top());
        prefeitos.pop();

    }
    while (!tempP.empty())
    {
        prefeitos.push(tempP.top());
        tempP.pop();
    }

    while (!prefeitos.empty())
    {
    cout << prefeitos.top().nome << " - " << prefeitos.top().numero << " - " << (prefeitos.top().votos / validos)* 100  << "%" << endl;
    prefeitos.pop();
    }


    cout << "Votos Brancos para Prefeito: " << brancosP.size() << endl;
    cout << "Votos Nulos para Prefeito: " << nulosP.size() << endl;
    float total = brancosP.size() + nulosP.size() + validos;

    float pBrancos =  (brancosP.size()* 100) / total ;
    float pNulos =  (nulosP.size()*100) /total;
    float pValidos = 100 - pBrancos - pNulos;

    cout << "Porcentagem de votos VALIDOS: " << pValidos << "%"<< endl;
    cout << "Porcentagem de votos BRANCOS: " << pBrancos << "%" << endl;
    cout << "Porcentagem de votos NULOS: " << pNulos << "%" << endl;


}




int main()
{
    
    PreencheUrna();
    Votacao();
    Dados();
}

