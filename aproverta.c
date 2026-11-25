#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void welcome(void);
int type_user(void);
char functions(void);
void fruits(void);
int main(void)
{
    welcome();
    int answer = type_user();
    string smiley = "Donde Jaime";
    if (answer == 1)
    {
        string name = get_string("¿Cómo se llama tu negocio?\n");
        // Con este prototipo no se utilizara esta informacion, pero se espera usarla para
        // proporcionar informacion mas precisa al usuario. Para saber el clima aproximado de la
        // region y asi saber que mecanismo de preservacion usar.
        string place = get_string("¿En qué ciudad/barrio esta tu negocio?\n");
        // Para saber la capacidad y el principa funcionamiento del negocio
        string kind = get_string("¿Qué tipo de negocio tienes?\nTienda\nFruver\nPuesto de mercado\nCarreta\n");
        //  Para saber como recomendar su almacenaje
        string sort = get_string("¿Qué productos vendes? *se despliega lista de productos*\n");
        // Para saber que medidas se utilizara para registrar los productos
        string measure = get_string("¿Cómo prefieres registrar tus cantidades?\nKilogramos (Kg)\nLibras (lb)\nUnidades (uds)\n");
        printf("¡Gracias por tu tiempo, conocerte nos permite brindarte una mejor experiencia! "
               "¡Disfruta de todas las funciones de AproVerta+!\n¿Qué quieres hacer ahora?\n");

        char respuesta = 's';
        while (respuesta == 's')
        {
            char task = functions();
            if (tolower(task) == 'a')
            { // Esto para saber cuando enviar las notificaciones, segun se haya programado el tiempo.
                string products = get_string("Selecciona en la lista los productos que tienes, si no los "
                    "encuentras, escribelos! *se despliega lista*\n");
                int condition = get_int("Indique el estado promedio de las frutas o el mas cercano.\n1. Verde\n2. Madura\n3. Pasada/Sobremadura\n");
                printf("Recibiras notificaciones preventivas sobre el estado de maduración de tus productos\n");
            }

            else if (tolower(task) == 'b')
            {
                fruits();
                // Tambien se pueden explicar otros procesos, como que es el gas etileno y lo que
                // provoca. Ademas de que cada fruta y verdudra tendra su ficha de informacion, para
                // que el usuraio pueda conocer a gusto Por otra parte he pensado en el uso de un
                // bot o IA destinada a responder preguntar y hacer mentorias personalizadas. Asi,
                // puede dar una ruta mas clara y precisa al usuario de como organizar sus productos
            }

            else
            {
                char si = 's';
                while (si == 's')
                {
                    char action = get_char(
                        "Comentanos que quieres hacer\na- Subir productos\nb- Crear promociones y "
                        "ofertas\nc- Publicar excedentes - Publica los productos que no lograste "
                        "vender para que otros puedan aprovecharlo -\n");
                    if (tolower(action) == 'a')
                    {
                        printf("Toma una foto referencia de todos tus productos para subirlos.\n");
                        // La idea es que el usuario nos diga cunaato compro en kg lb o unidades
                        // para llevar un registro interno y que cuando el cliente entre a la
                        // palicacion se vea si u producto esta disponible o no
                    }

                    else if (tolower(action) == 'b')
                    {
                        printf("Aqui te proporcionamos ideas de aprovechamientos para todos tus "
                               "productos incluso los que nadie ha querido comprar.\n");
                    }

                    else
                    {
                        printf("LLena la informacion correspondiente para que el excedente pueda "
                               "ser aprovechado de la mejor manera. Recuerda \"La basura de uno es el tesoro de otros\"\n");
                    }
                    si = get_char("Presione 's' para volver al menú anterior o 'x' para acabar\n");
                }
            }
            respuesta = get_char("Presione 's' para volver al menú principal o 'x' para acabar\n");
        }
    }

    else if (answer == 2)
    {
       int option = get_int("Si quieres unirte a un negocio y estar al tanto de sus productos y ofertas. Entonces prueba:\n1. Escanear código QR\n2. Escribir el nombre de la tienda\n");
        if (option == 1)
        {
            printf("* Se lee el QR* ¿Te quieres unir a '%s'? ", smiley);
            string join = get_string("Si es asi escriba 'si', de lo contrario 'no'\n");

            if (strcmp(join, "si") == 0)
            {
               printf("¡Felicidades! Ahora podrás ver las novedades, promociones y ofertas de '%s'. ¡AproVertalas!\n", smiley);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            printf("Por favor escriba el nombre del negocio que busca\n");
            printf("¡Felicidades! Ahora podrás ver las novedades, promociones y ofertas de '%s'. ¡AproVertalas!\n", smiley);
        }

        // La idea es que dentro del negocio el usuario pueda ver escoger y llenar su carrito para
        // pagar del modo que ella guste
    }
    else
    {
        printf("A continución puedes buscar y escoger el negocio de tu preferencia y conveniencia para estar al tanto de sus excedentes\n");
    }
}

void welcome(void)
{
    printf("¡Bienvenido(a) a AproVerta+, donde nos preocupamos por tu negocio!\nAntes de comenzar "
           "queremos conocer mejor tus intereses. Cuentanos, ¿cómo deseas utilizar la app?\n");
    return;
}

int type_user(void)
{
    int ans;
    ans = get_int("1- Soy vendedor.\n2- Soy cliente.\n3- Quiero aprovechar excedentes.\nEscribe el "
                  "número que corresponda con tu caso.\n");
    return ans;
}

char functions(void)
{
    char functions;
    functions = get_char("A- Registrar productos\nB- Cuida tus productos y organiza tu "
                         "mostrador\nC- Crear negocio digital\n");
    return functions;
}

void fruits(void)
{
    printf("Nos alegra que quieras conocer mas sobre los procesos naturales de tus productos. A "
           "continuación, una corta explicación del tipos de frutas que existen:\nFrutas "
           "climatéricas\nSon aquellas que pueden continuar madurando después de ser cosechadas. "
           "Durante este proceso presentan un aumento en la producción de etileno y en la "
           "respiración.\nAlgunos ejemplos son:\n- Banano\n- Mango\n- Aguacate\n- Papaya\n- "
           "Manzana\n- Pera\n\nFrutas no climatéricas\nSon aquellas que no presentan el mismo "
           "proceso de maduración después de ser cosechadas. Por eso, generalmente deben "
           "recolectarse cuando ya han alcanzado un grado adecuado de madurez.\n\nAlgunos ejemplos "
           "son:\n- Fresa\n- Uva\n- Naranja\n- Limón\n- Piña\n- Sandía\n");
    return;
}
