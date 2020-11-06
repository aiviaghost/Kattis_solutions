package life

object Main {
    val help = """
    Welcome to GAME OF LIFE!

    Click on cell to toggle.
    Press ENTER for next generation.
    Press SPACE to toggle play/stop.
    Press R to create random life.
    Press BACKSPACE to clear life.
    Close window to exit.
    """

    val dim = (30, 50)

    def main(args: Array[String]): Unit = {
        println(help)
        val w = new LifeWindow(dim._1, dim._2, args.length == 1 && args(0) == "multi")
        w.start()
    }
}
