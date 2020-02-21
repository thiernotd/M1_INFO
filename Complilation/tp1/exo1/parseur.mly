
%token NOMBRE FLOTTANT PLUS MOINS FOIS DIV MODULO GPAREN DPAREN EOL
%type <unit> main expression terme facteur
%start main
%%

main: 
   expression EOL            {}
 ;
expression: 
   expression PLUS terme       {}
 | expression MOINS terme      {}
 | terme                      {}
 ;
terme:
   terme FOIS facteur         {}
 | terme DIV facteur          {}
 | terme MODULO facteur       {}
 | facteur                    {}
 ;
facteur: 
   GPAREN expression DPAREN  {}
 | MOINS facteur             {}
 | NOMBRE                    {}
 | FLOTTANT                  {}
 ;

