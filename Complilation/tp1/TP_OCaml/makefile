all:
	ocamllex lexeur.mll
	ocamlyacc parseur.mly
	ocamlc -o TP AST.ml parseur.mli lexeur.ml parseur.ml TP.ml

clean:
	rm -rf TP parseur.mli parseur.ml lexeur.ml *.cmi *.cmo *~

