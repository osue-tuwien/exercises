#!/bin/bash

START=$(pwd)
PDFLATEX="pdflatex -interaction=nonstopmode -halt-on-error"

for file in $(find . -name "*.tex"); do
   cd $(dirname ${file})
   BASENAME=$(basename ${file})

   for i in {1..3}; do ${PDFLATEX} ${BASENAME} || exit 1; done
   # or the cooler latexmk
   #latexmk -pdf ${BASENAME}

   cd ${START}
done
