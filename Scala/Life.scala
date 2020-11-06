package life

import LifeWindow.Cell_states

case class Life(cells: Matrix[Boolean]) {
    def next_color(row: Int, col: Int): Int = Life.defaultRule(row, col, this)

    def is_inside(row: Int, col: Int): Boolean = { 0 <= row && row < cells.dim._1 && 0 <= col && col < cells.dim._2 }

    /** Ger true om cellen på plats (row, col) är vid liv annars false.
    * Ger false om indexeringen är utanför universums gränser.
    */
    def apply(row: Int, col: Int): Boolean = { is_inside(row, col) && cells(row, col) == true }

    /** Sätter status på cellen på plats (row, col) till value. */
    def updated(row: Int, col: Int, value: Boolean): Life = { if (is_inside(row, col)) Life(cells.updated(row, col)(value)) else this }

    /** Växlar status på cellen på plats (row, col). */
    def toggled(row: Int, col: Int): Life = { Life(cells.updated(row, col)(!this(row, col))) }

    /** Räknar antalet levande grannar till cellen i (row, col). */
    def nbrOfNeighbours(row: Int, col: Int): Int = {
        var count = 0
        val neighbours = Vector((-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1))
        for (next <- neighbours) { if (is_inside(row + next._2, col + next._1) && cells(row + next._2, col + next._1) == true) count += 1 }
        count
    }

    /** Skapar en ny Life-instans med nästa generation av universum.
    * Detta sker genom att applicera funktionen \code{rule} på cellerna.
    */
    def evolved(rule: (Int, Int, Life) => Int = Life.defaultRule):Life = {
        var nextGeneration = Life.empty(cells.dim)
        cells.foreachIndex { (r,c) =>
            val res = rule(r, c, this)
            val next_state = res == Cell_states.alive || res == Cell_states.will_be_born
            nextGeneration = nextGeneration.updated(r, c, next_state)
        }
        nextGeneration
    }

    /** Radseparerad text där 0 är levande cell och - är död cell. */
    override def toString = cells.toString
}

object Life {
    /** Skapar ett universum med döda celler. */
    def empty(dim: (Int, Int)): Life = { Life(Matrix(Vector.fill(dim._1, dim._2)(false))) }

    /** Skapar ett unviversum med slumpmässigt liv. */
    def random(dim: (Int, Int)): Life = Life(Matrix(Vector.fill(dim._1, dim._2)(scala.util.Random.nextDouble() < 0.5)))

    /** Implementerar reglerna enligt Conways Game of Life. */
    def defaultRule(row: Int, col: Int, current: Life): Int = {
        val neighbour_count = current.nbrOfNeighbours(row, col)
        if (current(row, col) && (neighbour_count == 2 || neighbour_count == 3)) {
            Cell_states.alive // true
        }
        else if (current(row, col) && neighbour_count < 2) {
            Cell_states.under_populated // false
        }
        else if (current(row, col) && neighbour_count > 3) {
            Cell_states.over_populated // false
        }
        else if (!current(row, col) && neighbour_count == 3) {
            Cell_states.will_be_born // true
        }
        else {
            Cell_states.dead // false
        }
    }
}
