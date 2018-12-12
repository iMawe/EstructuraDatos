**KDTree**
======

![IMAGE](https://github.com/iMawe/EstructuraDatos/blob/master/K-D%20Tree/Files/kdtree.png?raw=true)

- In computer science, a kd Tree (abbreviation of k-dimensional tree) is a data structure structure of the space that organizes the points in a Euclidean space of k dimensions.
- A kd tree uses only planes perpendicular to one of the axes of the coordinate system.
- All the nodes of a kd tree, from the root node to the leaf nodes, store a point.
- The idea is to maintain the notion of a binary tree, but cutting the space using a single orthogonal hyperplane. At each level of the tree we vary the cutting axis

For example:

In 2 dimensions at the root we cut perpendicular to the x axis; on the next level we cut perpendicular to
axis and, etc.

![IMAGE](https://github.com/iMawe/EstructuraDatos/blob/master/K-D%20Tree/Files/kdtree2.png?raw=true)

To represent this structure, a node is saved for each cut made. Each node has 2
children. All points smaller than the current cut point p, according to the discriminated axis,
they are saved in the children of the left, and in the ones of the right the majors (if the axis of a point
is equal to p, can be inserted in any of the two children. This is to try to balance the
subtrees). When you reach a point or a small number of points (less than or equal to
size of the bucket), it is stored in the leaves.

**How do we choose the cut value?**

For better performance, the decomposition of space
It should be as balanced as possible. The most common method used for this is to select
the cutoff value based on the median of the cutting axis. This produces a tree of height * O * (log n).
With a recursive procedure you can build the tree in * O * (n log n). The highest cost is
determine the median of the axis.

**Consultation of the nearest Neighbor**

Given a query point * q *, to look for the neighbor
Next, first, we descend through the tree. We keep a candidate point to be the most
next * nn * and a distance of maximum value * dist *. For each visited node we review this point,
updating it if necessary.
Then we need to check the subtrees. If * q * is on the underside of the hyperplane, we
we go to the left, otherwise to the right. After visiting the left subtree
we have modified the candidate point * nn * and the distance to this point * dist *.

##  **Uses KDTree**

**Orthogonal search in a kd tree**

Use a KDTree to find all the points that are in a certain rectangle (or analog of more dimensions). This operation is also called the orthogonal search range.

**Determine where to evaluate a surface**

In local regressions it is common to evaluate the surface contained directly only by the vertices of the KDTree and interpolate at some point. This use, reflected in the image above, seeks to ensure that only the necessary direct evaluations will be made. As the KDTree "adapt" to space, this method can provide an excellent approximation to the true local regression surfaces. If the approach is poor, it can be improved with more subdivisions.

## **Requirements**
- have Dev c ++
- download the files
- open the file.dev
- install the library *#include <winbgim.h>*
- install graphviz
- compile
## **References**

- http://www.cic.ipn.mx/aguzman/papers/89%20Arboles%20kd.htm
- https://es.wikipedia.org/wiki/%C3%81rbol_kd
- https://prezi.com/4lviwf2r7zoe/kd-tree/
- https://www.geeksforgeeks.org/k-dimensional-tree/
- https://www.geeksforgeeks.org/k-dimensional-tree-set-3-delete/
- https://www.mathworks.com/help/stats/kdtreesearcher.html












