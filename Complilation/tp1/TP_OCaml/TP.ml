
let _ =
  try
    let lexbuf = Lexing.from_channel stdin in
    while true do
      let ast = Parseur.main Lexeur.token lexbuf in
      AST.print_AST Format.std_formatter ast; Format.print_newline(); flush stdout
    done
  with 
   | Lexeur.Eof          ->  exit 0
   | Lexeur.TokenInconu 
   | Parsing.Parse_error ->  Printf.printf ("Ceci n'est pas une expression arithmétique\n")
 
