echo jaffar > ../week01/file.txt
link ../week01/file.txt _ex2.txt
ls -i ../week01/file.txt
find -inum 811347
find -inum 811347 -exec rm {} \;
find -inum 811347


