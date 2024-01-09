# A078:十字パズル
# 未完
import scala.io.StdIn._

class crossPuzzle(initCount: Int, initMatrix: Array[Array[Char]]){
    
    val rowCount = initCount
    var matrix = initMatrix
    
    // 同じ数字が十字に並んでいるか判定
    def judgeCross(rowNum: Int, lineNum: Int): Boolean = {
        
        // 有効範囲
        def isValidIndex(i: Int, j: Int): Boolean = {
          i >= 0 && i < rowCount && j >= 0 && j < 5
        }
        
        // 中央の値をセット
        val centerValue = matrix(rowNum)(lineNum)
    
        // 隣接場所
        val neighbors = Seq(
          (rowNum - 1, lineNum), // 上
          (rowNum + 1, lineNum), // 下
          (rowNum, lineNum - 1), // 左
          (rowNum, lineNum + 1)  // 右
        )
        
        // 隣接判定
        neighbors.forall { case (i, j) =>
          isValidIndex(i, j) && matrix(i)(j) == centerValue
        }
    }
    
    // 同じ数字が十字に並ぶブロックのタプルのリストを返す
    def findCross(): List[(Int, Int)] = {
        
        // for内包表記による判定
        (for {
          i <- 0 until rowCount
          j <- 0 until 5
          if judgeCross(i, j)
        } yield (i, j)).toList
    }
    
    // ブロック消去
    def eraseBlock(): Array[Array[Char]] = {
        def replace(matrix: Array[Array[Char]], crossList: List[(Int, Int)]): Array[Array[Char]] = {
          crossList match {
            case Nil => matrix
            case (row, line) :: tail =>
              val updatedMatrix = matrix.map(_.clone())
              updatedMatrix(row)(line) = '.' // .で置換
              replace(updatedMatrix, tail)
          }
        }
        val crossList = findCross()
        replace(matrix, crossList)
    }
    
    // ブロックの移動距離を算出
    def getMoveDistance(row: Int, line: Int): Int = {
        def calcDistance(matrix: Array[Array[Char]], currentRow: Int, counter: Int): Int = {
            currentRow match {
                case row if row == currentRow => counter
                case _ if matrix(currentRow+1)(line) == '.' => calcDistance(matrix, currentRow+1, counter+1)
                case _ => counter
            }
        }
        calcDistance(matrix, row, 0)
    }
    
    // ブロック下げ
    def slideDown(): Array[Array[Char]] = {
        // matrixが変更されるのでscala的には良くない書き方
        for(j <- 0 until 5){
            for(i <- rowCount-1 to 0 by -1){
                if(matrix(i)(j) != '.'){
                val mvDistance = getMoveDistance(i,j)
                    if(mvDistance != 0){
                        val moveBlockVal = matrix(i)(j)
                        matrix(i+mvDistance)(j) = moveBlockVal
                        matrix(i)(j) = '.'
                    }
                }
            }
        }
        matrix
    }
    
    // 問題を解く
    def solve(): Array[Array[Char]] = {
        def run(matrix: Array[Array[Char]]): Array[Array[Char]] = {
            val eraseMatrix = eraseBlock()
            val slideDownMatrix = slideDown()
            matrix match {
                case _ if matrix.sameElements(slideDownMatrix) => slideDownMatrix
                case _ => run(slideDownMatrix)
            }
        }
        run(matrix)
    }
}

object Main extends App {
    // 行数を取得
    val count = readInt()
    
    val matrix = Array.ofDim[Char](count, 5) // 5は列数
    
    for(i <- 0 until count){
        val lineStr = readLine()
        val lineArray = lineStr.toCharArray
        for(j <- 0 until 5){
            matrix(i)(j) = lineArray(j)
        }
    }
    
    val cp = new crossPuzzle(count, matrix)
    
    val resultMatrix = cp.solve()
    
    resultMatrix.foreach { row =>
        row.foreach { element =>
        print(element)
        }
        println()
    }
    
}