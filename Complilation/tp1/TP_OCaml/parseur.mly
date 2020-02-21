
%{
open AST
%}

%token <int> NOMBRE
%token <float> FLOTTANT
%token PLUS MOINS FOIS DIV MODULO GPAREN DPAREN EOL

%type <AST.expression_a> main expression terme facteur

%start main

%%

main: 
   expression EOL            { $1 }
 ;
expression: 
   expression PLUS terme     { Plus ($1,$3) }
 | expression MOINS terme    { Moins($1,$3) }
 | terme                     { $1 }
 ;
terme:
   terme FOIS facteur        { Mult ($1,$3) }
 | terme DIV facteur         { Div  ($1,$3) }
 | terme MODULO facteur      { Mod  ($1,$3) }
 | facteur                   { $1 }
 ;
facteur: 
   GPAREN expression DPAREN  { $2 }
 | MOINS facteur             { Neg $2 }
 | NOMBRE                    { Num $1 } 
 | FLOTTANT                  { Flot $1 } 
 ;
