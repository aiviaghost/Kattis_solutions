package life

case class Matrix[T](data: Vector[Vector[T]]){
    require(data.forall(_.length == data(0).length))
    val dim: (Int, Int) = (data.length, data(0).length)

    def apply(row: Int, col: Int): T = data(row)(col)

    def updated(row: Int, col: Int)(value: T): Matrix[T] = { Matrix(data.updated(row, data(row).updated(col, value))) }
  
    def foreachIndex(f: (Int, Int) => Unit): Unit = for(r <- data.indices; c <- data(r).indices) f(r, c)
  
    override def toString: String = { s"Matrix of dim $dim:\n" + (for(row <- data) yield row.mkString.replace("false", "-").replace("true", "0")).mkString("\n") }
}
object Matrix {
    def fill[T](dim: (Int, Int))(value: T): Matrix[T] = Matrix(Vector.fill(dim._1, dim._2)(value))
}
