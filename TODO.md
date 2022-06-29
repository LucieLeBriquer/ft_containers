# to fix
pour Map :
- il va falloir refaire tout le système d'itérateur pour parcourir l'arbre binaire vu que l'objet est splitted sur plusieurs parties de la mémoire
- `begin() { return (iterator(_tree)); }`
- iterator et iterator traits sont encore valables, il va falloir faire des `bst_iterator`
- parcours préfixe pour avoir la map triée
- _current = _tree
- changer les opérations `++`, `--` etc
/!\
- correction -> arbre doit rester equilibre
- tout mettre sous forme copelienne

ft::RedBlackTree<ft::pair<int, std::string >, ft::map<int, std::string, ft::less<int>, std::allocator<ft::pair<const int, std::string > > >::value_compare>::NodeP'
(aka 'Node<ft::pair<int, std::string > > *')
to 'ft::map<int, std::string, ft::less<int>, std::allocator<ft::pair<const int, std::string > > >::iterator'
(aka 'normal_iterator<RedBlackIterator<pair<int, std::string >, ft::map<int, std::string, ft::less<int>, std::allocator<ft::pair<const int, std::string > > >::value_compare>, ft::map<int, std::string, ft::less<int>, std::allocator<ft::pair<const int, std::string > > > >