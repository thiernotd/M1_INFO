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

val main :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> AST.expression_a
