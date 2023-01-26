package advanced;

import java.util.*;

enum Color {
    RED, GREEN
}

abstract class Tree {
    private final int value;
    private final Color color;
    private final int depth;

    public Tree(int value, Color color, int depth) {
        this.value = value;
        this.color = color;
        this.depth = depth;
    }

    public int getValue() {
        return value;
    }

    public Color getColor() {
        return color;
    }

    public int getDepth() {
        return depth;
    }

    public abstract void accept(TreeVis visitor);
}

class TreeNode extends Tree {
    private final ArrayList<Tree> children = new ArrayList<>();

    public TreeNode(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitNode(this);

        for (Tree child : children) {
            child.accept(visitor);
        }
    }

    public void addChild(Tree child) {
        children.add(child);
    }
}

class TreeLeaf extends Tree {
    public TreeLeaf(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitLeaf(this);
    }
}

abstract class TreeVis {
    public abstract int getResult();

    public abstract void visitNode(TreeNode node);

    public abstract void visitLeaf(TreeLeaf leaf);

}

class SumInLeavesVisitor extends TreeVis {
    int result = 0;

    public int getResult() {
        return result;
    }

    public void visitNode(TreeNode node) {
        // do nothing
    }

    public void visitLeaf(TreeLeaf leaf) {
        result += leaf.getValue();
    }
}

class ProductOfRedNodesVisitor extends TreeVis {
    final int M = 1000000007;
    long result = 1;

    public int getResult() {
        return (int) result;
    }

    public void visitNode(TreeNode node) {
        if (node.getColor() == Color.RED) {
            result = (result * node.getValue()) % M;
        }
    }

    public void visitLeaf(TreeLeaf leaf) {
        if (leaf.getColor() == Color.RED) {
            result = (result * leaf.getValue()) % M;
        }
    }
}

class FancyVisitor extends TreeVis {
    int result = 0;

    public int getResult() {
        return Math.abs(result);
    }

    public void visitNode(TreeNode node) {
        if (node.getDepth() % 2 == 0) {
            result += node.getValue();
        }
    }

    public void visitLeaf(TreeLeaf leaf) {
        if (leaf.getColor() == Color.GREEN) {
            result -= leaf.getValue();
        }
    }
}

public class VisitorPattern {
    static int[] values;
    static Color[] colors;
    static Map<Integer, Set<Integer>> nodesMap = new HashMap<>();

    public static Tree solve() {
        Scanner in = new Scanner(System.in);
        int noNodes = in.nextInt();
        values = new int[noNodes];
        for (int i = 0; i < noNodes; i++)
            values[i] = in.nextInt();
        colors = new Color[noNodes];
        for (int i = 0; i < noNodes; i++)
            colors[i] = (in.nextInt() == 0) ? Color.RED : Color.GREEN;
        Tree rootNode;
        if (noNodes == 1) {
            rootNode = new TreeLeaf(values[0], colors[0], 0);
        } else {
            rootNode = new TreeNode(values[0], colors[0], 0);
            for (int i = 0; i < (noNodes - 1); i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                Set<Integer> uEdges = nodesMap.get(u);
                if (uEdges == null)
                    uEdges = new HashSet<>();
                uEdges.add(v);
                nodesMap.put(u, uEdges);
                Set<Integer> vEdges = nodesMap.get(v);
                if (vEdges == null)
                    vEdges = new HashSet<>();
                vEdges.add(u);
                nodesMap.put(v, vEdges);
            }
            for (int nodeId : nodesMap.get(1)) {
                nodesMap.get(nodeId).remove(1);
                createEdge(rootNode, nodeId);
            }
        }
        in.close();
        return rootNode;
    }

    private static void createEdge(Tree parent, int nodeId) {
        Set<Integer> nodeEdges = nodesMap.get(nodeId);
        boolean hasChild = nodeEdges != null && !nodeEdges.isEmpty();
        if (hasChild) {
            TreeNode node = new TreeNode(values[nodeId - 1], colors[nodeId - 1], parent.getDepth() + 1);
            ((TreeNode) parent).addChild(node);
            for (int neighborId : nodeEdges) {
                nodesMap.get(neighborId).remove(nodeId);
                createEdge(node, neighborId);
            }
        } else {
            TreeLeaf leaf = new TreeLeaf(values[nodeId - 1], colors[nodeId - 1], parent.getDepth() + 1);
            ((TreeNode) parent).addChild(leaf);
        }
    }

    public static void main(String[] args) {
        Tree root = solve();
        TreeVis[] treeVisitors = new TreeVis[]{
                new SumInLeavesVisitor(),
                new ProductOfRedNodesVisitor(),
                new FancyVisitor()
        };
        for (TreeVis visitor : treeVisitors) {
            root.accept(visitor);
            System.out.println(visitor.getResult());
        }
    }
}