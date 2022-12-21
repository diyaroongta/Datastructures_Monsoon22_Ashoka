//Finding the minimum node of the tree

NodeAddress min (NodeAddress root)
{
    NodeAddress x = root;
    while (x -> left)
        x = x -> left;
    return x;
}

//AVL tree maximum
NodeAddress maximum (NodeAddress root)
{
    NodeAddress x = root;
    while (x -> right)
        x = x -> right;
    return x;
}
