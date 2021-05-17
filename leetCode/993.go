func dp(parNode *TreeNode, curNode *TreeNode, value int)(*TreeNode, int) {

	if curNode == nil {
		return nil, -1
	}

	if curNode.Val == value {
		return parNode, 1
	}
	
	resultNode, deep := dp(curNode, curNode.Left, value);

	if deep > 0 {
		return resultNode, deep+1
	}

	resultNode, deep = dp(curNode, curNode.Right, value);
	if deep > 0 {
		return resultNode, deep+1
	}

	return resultNode, deep
  }

func isCousins(root *TreeNode, x int, y int) bool {

	xPar, xd := dp(nil, root, x)

	yPar, yd := dp(nil, root, y)

	if xd == -1 || yd == -1 {
	return false
    }

	return xd == yd && xPar != yPar
}