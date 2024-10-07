#### Summary of Chapter One ####

Much of computational geometry performs its operations on polygons.

`A Polygon is a region of a plane bounded by a collection of line segments forming a simple closed curve`

However, that is a long sentence made up of key words that are themselves loosely or differently defined 
depending on which branch of mathematics you happen to belong to and how preceise you want to be.
I think there is lots of hidden meaning within the powerset of keywords in the sentence and the implied, 
unspoken, topics outside the sentence given, so ...

My engineering mind says a polygon is whatever data structure that makes the calculations easier.

We can also experiment with different definitions and different data structures to find out what 
suits the algorithms and real world models best.

`Therem 1.1.1 Jordan's curve theorem - Every simple closed plane curve divides the plane into two components, 
the boundaed interior of the curve and the unbounded exterior`

An obvious statement which is difficult to prove. 

Often a polygon is considered to be the segments bounding 
the region, and not the region itself. In the book, the notation of delta P is used to represent the 
boundary of P, where $$\delta P \subseteq P$$. Allowing for the limitations of the mathematical symbols
in github markdown, delta P uses symbol for the partial derivative!

By convention, the vertices of a polygon are listed in counterclockwise order, such that the interior region
is always to the left when following a boundary traversal.

`Theorem 1.1.2 the art gallery theorem - how many points of light are needed to illuminate the entire polygon`



