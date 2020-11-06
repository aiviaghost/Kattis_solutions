package life

import introprog.PixelWindow
import introprog.PixelWindow.Event

object LifeWindow {
    import java.awt.{Color => JColor}

    val EventMaxWait = 1 // milliseconds
    var NextGenerationDelay = 200 // milliseconds
    // lägg till fler användbara konstanter här tex färger etc.
    val blockSize = 20

    // colors:
    object Colors {
        val line_color = new JColor(95, 95, 95)
        val alive = new JColor(242, 128, 161)
        val dead = JColor.BLACK
        val will_be_born = new JColor(60, 0, 0)
        val under_populated = JColor.CYAN
        val over_populated = JColor.RED
    }

    // used to determine color
    object Cell_states {
        val alive = 0
        val under_populated = 1
        val over_populated = 2
        val will_be_born = 3
        val dead = 4
    }
}

class LifeWindow(rows: Int, cols: Int, is_multi_color: Boolean){
    import LifeWindow._ // importera namn från kompanjon

    var life = Life.empty(rows, cols)
    val window: PixelWindow = new PixelWindow(cols * blockSize, rows * blockSize, "Life")
    var quit = false
    var play = false

    def drawGrid(): Unit = {
        for (i <- 0 until cols) {
            window.line(i * blockSize, 0, i * blockSize, rows * blockSize, Colors.line_color)
        }

        for (i <- 0 until rows) {
            window.line(0, i * blockSize, cols * blockSize, i * blockSize, Colors.line_color)
        }
    }

    def drawCell(row: Int, col: Int): Unit = {
        val next_color = {
            if (is_multi_color) {
                life.next_color(row, col) match {
                    case Cell_states.alive => Colors.alive
                    case Cell_states.under_populated => Colors.under_populated
                    case Cell_states.over_populated => Colors.over_populated
                    case Cell_states.will_be_born => Colors.will_be_born
                    case Cell_states.dead => Colors.dead
                }
            }
            else {
                if (life(row, col)) Colors.alive else Colors.dead
            }
        }
        window.fill(col * blockSize + 1, row * blockSize + 1, blockSize - 1, blockSize - 1, next_color)
    }

    def update(newLife: Life): Unit = {
        life = newLife
        life.cells.foreachIndex{ drawCell }
    }

    def handleKey(key: String): Unit = {
        key match {
            case "Enter" => update(life.evolved())
            case "Backspace" => update(Life.empty(rows, cols))
            case "r" => update(Life.random(rows, cols))
            case " " => play = !play
            // case _ if key.length == 1 && key.toCharArray()(0).toInt == 32 => play = !play // "space" character
            case _ => 
        }
    }

    def handleClick(pos: (Int, Int)): Unit = {
        update(life.toggled((pos._2 / blockSize).toInt, (pos._1 / blockSize).toInt))
    }

    def loopUntilQuit(): Unit = while (!quit) {
        val t0 = System.currentTimeMillis
        if (play) update(life.evolved())
        window.awaitEvent(EventMaxWait)
        while (window.lastEventType != PixelWindow.Event.Undefined) {
            window.lastEventType match {
                case Event.KeyPressed   => handleKey(window.lastKey)
                case Event.MousePressed => handleClick(window.lastMousePos)
                case Event.WindowClosed => quit = true
                case _ =>
            }
            window.awaitEvent(EventMaxWait)
        }
        val elapsed = System.currentTimeMillis - t0
        Thread.sleep((NextGenerationDelay - elapsed) max 0)
    }

    def start(): Unit = { drawGrid(); loopUntilQuit() }
}
