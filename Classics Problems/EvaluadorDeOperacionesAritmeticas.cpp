#include <bits/stdc++.h>

using namespace std;

enum class TokenType { // el token es la operacion, numero o simbolo minimo divisible valido en nuestra expresion.
    NUMERO,
    SUMA, // operaciones
    RESTA,
    MULTIPLICACION,
    DIVISION,
    EXPO,
    PARDER, //parentesis 
    PARIZQ
};

struct Token {
    TokenType type; //este enum nos servira para tener claro y restringir y expandir de forma simple nuestras operaciones, si queremos añadir mas sera mas simple.
    double value;  // solo se usa si el tipo es NUMBER

    Token(TokenType type) : type(type), value(0) {}
    Token(TokenType type, double value) : type(type), value(value) {}
};

bool esOperador(char c) {
    return c == '+' or c == '*' or c == '-' or c == '/' or c=='^';
}

bool esNumero(string &s) { // dado que esta cadena solo tiene numeros y puntos, solo hay que comprobar que solo hay un punto. (ya se checo que no se empiece con punto, aqui creo que sera mejor verificar que no se acabe con punto).
    return s[s.size()-1] != '.' and count(begin(s), end(s), '.') <= 1;
}

vector<Token> tokenisa(string s) { // convertiremos toda nuestra expresion a token, si y solo si es un token valido.
    //Si hay un token invalido regresamos un vector de tokens vacio
    
    //primer paso borrar los espacios a la expresion
    string aux = "";
    for(char c:s) 
        if(c!=' ')aux += c;
    s = aux;
    
    vector<Token> tokens;
    for (int i = 0; i < s.size(); i++) {
        //hay que tener cuidado al detectar numero negativos
        if ((s[i]>='0' and s[i]<='9') or (s[i] == '-' and i+1<s.size() and s[i+1]>='0' and s[i+1]<='9' and (i==0 or (i-1>=0 and esOperador(s[i-1]))))) { // esta parte despues del or resuelve el problema de los numeros negativos. 
            string posibleNumero = "";
            if(s[i] == '-'){
                posibleNumero+='-';
                i++;
            }
            while(i<s.size() and ((s[i]>='0' and s[i]<='9') or s[i] == '.')) { // mientras que sea numero o punto agrega
                posibleNumero += s[i];
                i++;
            }
            i--;//restamos -1 por que despues se le va a sumar uno en el for
            if(esNumero(posibleNumero)) {
                tokens.push_back(Token(TokenType::NUMERO, stod(posibleNumero)));
            } else {
                throw runtime_error(posibleNumero+" no es un numero valido");
            }
        } else if (esOperador(s[i])) {
            if (s[i] == '+') {
                tokens.push_back(Token(TokenType::SUMA));
            } else if(s[i] == '-') {
                tokens.push_back(Token(TokenType::RESTA));
            } else if(s[i] == '*') {
                tokens.push_back(Token(TokenType::MULTIPLICACION));
            } else if(s[i] == '/') {
                tokens.push_back(Token(TokenType::DIVISION));
            } else if(s[i] == '^') {
                tokens.push_back(Token(TokenType::EXPO));
            }
        } else if (s[i] == ' ') { // ignoramos espacios
            continue;
        } else if(s[i] == '(') {
            tokens.push_back(Token(TokenType::PARIZQ));
        } else if(s[i] == ')') {
            tokens.push_back(Token(TokenType::PARDER));
        } else { //ese token no existe
            throw runtime_error("Caracter no reconocido en la expresion: "+s[i]);
        }
    }
    return tokens;
}

bool esOperador(Token t) {
    return t.type == TokenType::SUMA or t.type == TokenType::RESTA or t.type == TokenType::MULTIPLICACION or t.type == TokenType::DIVISION or t.type == TokenType::EXPO;
}

bool verificaExpresion(vector<Token> &Tokens) {
    if (Tokens.empty()) {
        cout<<"expresion invalida o vacia..."<<endl;
        return false;
    }
    //checa parentesis
    //Si en algun punto es negativo se estan cerrando mal
    //Si se acaba diferente de 0 esta mal
    int parentesisStatus = 0;
    for(Token t:Tokens) {
        if (t.type == TokenType::PARIZQ)parentesisStatus++;
        else if(t.type == TokenType::PARDER)parentesisStatus--;
        if (parentesisStatus<0) {
            cout<<"Expresion incorrecta, parentes mal colocados"<<endl;
            return false;
        }
    }
    if (parentesisStatus != 0) {
        cout<<"Expresion incorrecta, parentesis mal colocados"<<endl;
        return false;
    }
    //El primero o ultimo token NO pueden ser operadores, tampoco puede haber dos juntos.
    if (esOperador(Tokens[0]) or esOperador(Tokens[Tokens.size()-1])) {
        //Si puede haber negativo al principio
        cout<<"No puede haber operadores al principio o al final de la expresion"<<endl;
        return false;
    }
    for(int i = 1;i<Tokens.size()-2;i++) {
        if(esOperador(Tokens[i]) and esOperador(Tokens[i+1])) {
            cout<<"No puede haber dos operadores juntos..."<<endl;
            return false;
        }
    }
    for(int i = 1;i<Tokens.size()-2;i++) {
        if(Tokens[i].type == TokenType::PARDER and Tokens[i+1].type==TokenType::PARIZQ) {
            cout<<"No puede haber parentesis sin operacion entre ellos"<<endl;
            return false;
        }
    }
    for(int i = 0;i<Tokens.size()-2;i++) {
        if(Tokens[i].type == TokenType::NUMERO and Tokens[i+1].type==TokenType::PARIZQ) {
            cout<<"No puede haber parentesis junto a numero sin operacion entre ellos"<<endl;
            return false;
        }
        if(Tokens[i].type == TokenType::PARDER and Tokens[i+1].type==TokenType::NUMERO) {
            cout<<"No puede haber parentesis junto a numero sin operacion entre ellos"<<endl;
            return false;
        }
    }
    return true;
}
 
void printTokens(vector<Token> &v) { //util para debuggear
    for (Token i : v) { 
        if (i.type == TokenType::SUMA)
            cout << "+ ";
        else if (i.type == TokenType::RESTA)
            cout << "- ";
        else if (i.type == TokenType::MULTIPLICACION)
            cout << "* ";
        else if (i.type == TokenType::DIVISION)
            cout << "/ ";
        else if (i.type == TokenType::EXPO)
            cout << "^ ";
        else if (i.type == TokenType::PARIZQ)
            cout << "( ";
        else if (i.type == TokenType::PARDER)
            cout << ") ";
        else if (i.type == TokenType::NUMERO)
            cout << "numero " << i.value << " ";
    }
    cout<<endl;
}

// Función de evaluación usando rangos
double Evalua(vector<Token> &tokens, int indIni, int indFin) {
    
    // Caso base: Si el rango es un único token, debe ser un número.
    if(indIni == indFin) {
        if(tokens[indIni].type == TokenType::NUMERO)
            return tokens[indIni].value;
        else
            throw runtime_error("Token inesperado en la evaluación");
    }
    
    // Si el segmento está completamente encerrado en paréntesis, descarta esos paréntesis.
    if(tokens[indIni].type == TokenType::PARIZQ && tokens[indFin].type == TokenType::PARDER) {
        int count = 0;
        bool completamenteEncerrado = true;
        for (int i = indIni; i <= indFin; i++) {
            if(tokens[i].type == TokenType::PARIZQ)
                count++;
            else if(tokens[i].type == TokenType::PARDER)
                count--;
            // Si el contador se hace 0 antes del final, los paréntesis no encierran toda la expresión.
            if(count == 0 && i < indFin) {
                completamenteEncerrado = false;
                break;
            }
        }
        if(completamenteEncerrado)
            return Evalua(tokens, indIni+1, indFin-1);
    }
    
    // Busca el operador principal (fuera de cualquier paréntesis) en el rango [indIni, indFin]
    int opPos = -1;
    int minPrec = INT_MAX; // mantiene al operador de menor precedencia
    int level = 0;
    for (int i = indIni; i <= indFin; i++) {
        Token curr = tokens[i];
        if(curr.type == TokenType::PARIZQ) {
            level++;
        } else if(curr.type == TokenType::PARDER) {
            level--;
        } else if(level == 0 && esOperador(curr)) {
            int prec = 0;
            switch(curr.type) {
                case TokenType::SUMA:
                case TokenType::RESTA: 
                    prec = 1; 
                    break;
                case TokenType::MULTIPLICACION:
                case TokenType::DIVISION: 
                    prec = 2; 
                    break;
                case TokenType::EXPO: 
                    prec = 3; 
                    break;
                default: break;
            }
            // Si encontramos un operador con menor precedencia, actualizamos
            if(prec < minPrec) {
                minPrec = prec;
                opPos = i;
            } else if(prec == minPrec) { // se dejan al reves para que en el arbol de subproblemas a resolver esto se resuelvan al ultimo y al principio se resulvan los de menor prioridad.
                // Para operadores left-associative (suma, resta, multiplicacion, division) usamos el derecho.
                if(curr.type == TokenType::SUMA || curr.type == TokenType::RESTA ||
                   curr.type == TokenType::MULTIPLICACION || curr.type == TokenType::DIVISION) {
                    opPos = i;
                }
                // Para '^' (right-associative) dejamos el primero encontrado. (el que esta mas a la izquierda)
            }
        }
    }
    
    // Si no se encontró ningún operador a nivel 0, la expresión debería ser un número o está mal formada.
    if(opPos == -1) {
        if(indIni == indFin && tokens[indIni].type == TokenType::NUMERO)
            return tokens[indIni].value;
        else
            throw runtime_error("Expresión mal formada");
    }
    
    // Evalúa recursivamente la parte izquierda y la parte derecha
    double leftVal = Evalua(tokens, indIni, opPos - 1);
    double rightVal = Evalua(tokens, opPos + 1, indFin);
    
    // Aplica el operador encontrado
    switch(tokens[opPos].type) {
        case TokenType::SUMA:
            return leftVal + rightVal;
        case TokenType::RESTA:
            return leftVal - rightVal;
        case TokenType::MULTIPLICACION:
            return leftVal * rightVal;
        case TokenType::DIVISION:
            if(rightVal == 0) 
                throw runtime_error("División por cero");
            return leftVal / rightVal;
        case TokenType::EXPO:
            return pow(leftVal, rightVal);
        default:
            throw runtime_error("Operador desconocido");
    }
}

int main() {
    string s;
    getline(cin, s); // leemos con todo y espacios la expresion
    vector<Token> v = tokenisa(s);
    //printTokens(v); // para debuggear
    
    if(verificaExpresion(v)) { // Si la expresion ya es valida, podemos pasar a evaluar.
        cout<<Evalua(v, 0, v.size()-1)<<endl;
    }
    return 0;
}
