/**查找**/
Position Find( ElementType X, SPTree *tree )
{
    if( tree == NULL )
        return NULL;
    if( X < (*tree)->Element )
    {
        if( (*tree)->Left == NULL )
        {
            //查找失败，此时 tree 为伸展节点
            return NULL;
        }
        else if( X == (*tree)->Left->Element )
        {
            //查找成功，此时对应最简单的情况，将根节点的左孩子移动到根的位置
            SingleRotateWithLeft( tree );
			return (*tree);	
        }
        else if( X < (*tree)->Left->Element )
        {
            if( (*tree)->Left->Left == NULL )
            {
                //查找失败，此时伸展节点是 tree->Left
                SingleRotateWithLeft( tree );
				return NULL;
            }
            else if( X == (*tree)->Left->Left->Element )
            {
                //此时对应左左情况
				SingleRotateWithLeft( &((*tree)->Left) );
				return (*tree)->Left;
            }
            else
                //递归地在 tree 的左子树的左子树中进行查找
                return Find( X, &( (*tree)->Left->Left ) );
        }
        else
        {
            if( (*tree)->Left->Right == NULL )
            {
                //查找失败，此时伸展节点是 tree->Left
				SingleRotateWithLeft( tree );
                return NULL;
            }
            if( X == (*tree)->Left->Right->Element )
            {
                //此时对应左右情况
				DoubleRotateWithLeft( tree );	
				return *tree;
            }
            else
                //递归地在 tree 的左子树的右子树中进行查找
                return Find( X, &((*tree)->Left->Right) );
        }
    }
    else if( X > (*tree)->Element )
    {
        if( (*tree)->Right == NULL )
            //查找失败，此时 tree 是伸展节点
            return NULL;
        else if( X == (*tree)->Right->Element )
        {
            //此时对应最简单的情况，根节点的右孩子是伸展节点
            SingleRotateWithRight( tree );
			return *tree;
        }
        else if( X > (*tree)->Right->Element )
        {
            if( (*tree)->Right->Right == NULL )
            {
                //查找失败，此时伸展节点是 tree->Right
				SingleRotateWithRight( tree );
                return NULL;
            }
            else if( X == (*tree)->Right->Right->Element )
            {
                //此时对应右右情况
				SingleRotateWithRight( &((*tree)->Right) );
				return (*tree)->Right;
            }
            else
                //递归地在 tree 的右子树的右子树进行查找
                return Find( X, &((*tree)->Right->Right) );
        }
        else
        {
            if( (*tree)->Right->Left == NULL )
            {
                //查找失败，此时伸展节点是 tree->Right
				SingleRotateWithRight( tree );
                return NULL;
            }
            else if( X == (*tree)->Right->Left->Element )
            {
                //此时对应右左情况
				DoubleRotateWithRight( tree );
				return (*tree);
            }
            else
                //递归地在 tree 的右子树的左子树进行查找
                return Find( X, &((*tree)->Right->Left) );
        }
    }
    else
    {
        //这种情况下要查找的元素就在根节点中，直接返回
        return (*tree);
    }
} 
