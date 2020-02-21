type token =
  | NOMBRE of (int)
  | FLOTTANT of (float)
  | PLUS
  | MOINS
  | FOIS
  | DIV
  | MODULO
  | GPAREN
  | DPAREN
  | EOL

open Parsing;;
let _ = parse_error;;
# 3 "parseur.mly"
open AST
# 18 "parseur.ml"
let yytransl_const = [|
  259 (* PLUS *);
  260 (* MOINS *);
  261 (* FOIS *);
  262 (* DIV *);
  263 (* MODULO *);
  264 (* GPAREN *);
  265 (* DPAREN *);
  266 (* EOL *);
    0|]

let yytransl_block = [|
  257 (* NOMBRE *);
  258 (* FLOTTANT *);
    0|]

let yylhs = "\255\255\
\001\000\002\000\002\000\002\000\003\000\003\000\003\000\003\000\
\004\000\004\000\004\000\004\000\000\000"

let yylen = "\002\000\
\002\000\003\000\003\000\001\000\003\000\003\000\003\000\001\000\
\003\000\002\000\001\000\001\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\011\000\012\000\000\000\000\000\013\000\000\000\
\000\000\008\000\010\000\000\000\000\000\000\000\001\000\000\000\
\000\000\000\000\009\000\000\000\000\000\005\000\006\000\007\000"

let yydgoto = "\002\000\
\007\000\008\000\009\000\010\000"

let yysindex = "\002\000\
\000\255\000\000\000\000\000\000\000\255\000\255\000\000\018\255\
\027\255\000\000\000\000\026\255\000\255\000\255\000\000\000\255\
\000\255\000\255\000\000\027\255\027\255\000\000\000\000\000\000"

let yyrindex = "\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\006\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\014\255\016\255\000\000\000\000\000\000"

let yygindex = "\000\000\
\000\000\001\000\248\255\251\255"

let yytablesize = 35
let yytable = "\011\000\
\003\000\004\000\001\000\005\000\020\000\021\000\012\000\006\000\
\004\000\004\000\022\000\023\000\024\000\000\000\004\000\004\000\
\002\000\002\000\003\000\003\000\013\000\014\000\002\000\002\000\
\003\000\003\000\000\000\015\000\013\000\014\000\000\000\016\000\
\017\000\018\000\019\000"

let yycheck = "\005\000\
\001\001\002\001\001\000\004\001\013\000\014\000\006\000\008\001\
\003\001\004\001\016\000\017\000\018\000\255\255\009\001\010\001\
\003\001\004\001\003\001\004\001\003\001\004\001\009\001\010\001\
\009\001\010\001\255\255\010\001\003\001\004\001\255\255\005\001\
\006\001\007\001\009\001"

let yynames_const = "\
  PLUS\000\
  MOINS\000\
  FOIS\000\
  DIV\000\
  MODULO\000\
  GPAREN\000\
  DPAREN\000\
  EOL\000\
  "

let yynames_block = "\
  NOMBRE\000\
  FLOTTANT\000\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 1 : AST.expression_a) in
    Obj.repr(
# 17 "parseur.mly"
                             ( _1 )
# 102 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : AST.expression_a) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 20 "parseur.mly"
                             ( Plus (_1,_3) )
# 110 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : AST.expression_a) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 21 "parseur.mly"
                             ( Moins(_1,_3) )
# 118 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 22 "parseur.mly"
                             ( _1 )
# 125 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : AST.expression_a) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 25 "parseur.mly"
                             ( Mult (_1,_3) )
# 133 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : AST.expression_a) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 26 "parseur.mly"
                             ( Div  (_1,_3) )
# 141 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : AST.expression_a) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 27 "parseur.mly"
                             ( Mod  (_1,_3) )
# 149 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 28 "parseur.mly"
                             ( _1 )
# 156 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : AST.expression_a) in
    Obj.repr(
# 31 "parseur.mly"
                             ( _2 )
# 163 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : AST.expression_a) in
    Obj.repr(
# 32 "parseur.mly"
                             ( Neg _2 )
# 170 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : int) in
    Obj.repr(
# 33 "parseur.mly"
                             ( Num _1 )
# 177 "parseur.ml"
               : AST.expression_a))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : float) in
    Obj.repr(
# 34 "parseur.mly"
                             ( Flot _1 )
# 184 "parseur.ml"
               : AST.expression_a))
(* Entry main *)
; (fun __caml_parser_env -> raise (Parsing.YYexit (Parsing.peek_val __caml_parser_env 0)))
|]
let yytables =
  { Parsing.actions=yyact;
    Parsing.transl_const=yytransl_const;
    Parsing.transl_block=yytransl_block;
    Parsing.lhs=yylhs;
    Parsing.len=yylen;
    Parsing.defred=yydefred;
    Parsing.dgoto=yydgoto;
    Parsing.sindex=yysindex;
    Parsing.rindex=yyrindex;
    Parsing.gindex=yygindex;
    Parsing.tablesize=yytablesize;
    Parsing.table=yytable;
    Parsing.check=yycheck;
    Parsing.error_function=parse_error;
    Parsing.names_const=yynames_const;
    Parsing.names_block=yynames_block }
let main (lexfun : Lexing.lexbuf -> token) (lexbuf : Lexing.lexbuf) =
   (Parsing.yyparse yytables 1 lexfun lexbuf : AST.expression_a)
