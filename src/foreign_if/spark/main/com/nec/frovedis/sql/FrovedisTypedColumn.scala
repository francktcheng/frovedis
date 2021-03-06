package com.nec.frovedis.sql;

import scala.reflect.ClassTag
import org.apache.spark.SparkContext
import org.apache.spark.sql.SparkSession
import org.apache.spark.sql.DataFrame
import com.nec.frovedis.Jexrpc._
import OPTYPE._

object DummyDF {
  var dummy: DataFrame = null
  def get(): DataFrame = {
    if (dummy == null) {
      val spark = SparkSession.builder.getOrCreate()
      import spark.implicits._
      val sc = SparkContext.getOrCreate()
      dummy = sc.parallelize(Array(1,2,3,4)).toDF("one")
    }
    return dummy
  }
}

class FrovedisTypedColumn extends java.io.Serializable {
  protected var col_name: String = null
  protected var type_name: Short = 0

  def this(name: String, tid: Short) = {
    this()
    col_name = name
    type_name = tid
  }
  // if not same class, then it would be assumed as an 'immed' operation
  private def isImmed(arg: Any): Boolean = {
    if (ClassTag(this.getClass) == ClassTag(arg.getClass)) return false
    val dummy_spark_df = DummyDF.get() 
    val spark_col = dummy_spark_df("one")
    if (ClassTag(arg.getClass) == ClassTag(spark_col.getClass)) return false
    else return true
  }
  def >(arg: Any): DFOperator = {
    val fs = FrovedisServer.getServerInstance()
    val proxy = JNISupport.getDFOperator(fs.master_node,toString(),
                                         arg.toString(),dtype(),GT,isImmed(arg))
    return new DFOperator(proxy)
  }
  def >=(arg: Any): DFOperator = {
    val fs = FrovedisServer.getServerInstance()
    val proxy = JNISupport.getDFOperator(fs.master_node,toString(),
                                         arg.toString(),dtype(),GE,isImmed(arg))
    return new DFOperator(proxy)
  }
  def <(arg: Any): DFOperator = {
    val fs = FrovedisServer.getServerInstance()
    val proxy = JNISupport.getDFOperator(fs.master_node,toString(),
                                         arg.toString(),dtype(),LT,isImmed(arg))
    return new DFOperator(proxy)
  }
  def <=(arg: Any): DFOperator = {
    val fs = FrovedisServer.getServerInstance()
    val proxy = JNISupport.getDFOperator(fs.master_node,toString(),
                                         arg.toString(),dtype(),LE,isImmed(arg))
    return new DFOperator(proxy)
  }
  def ===(arg: Any): DFOperator = {
    val fs = FrovedisServer.getServerInstance()
    val proxy = JNISupport.getDFOperator(fs.master_node,toString(),
                                         arg.toString(),dtype(),EQ,isImmed(arg))
    return new DFOperator(proxy)
  }
  def !==(arg: Any): DFOperator = {
    val fs = FrovedisServer.getServerInstance()
    val proxy = JNISupport.getDFOperator(fs.master_node,toString(),
                                         arg.toString(),dtype(),NE,isImmed(arg))
    return new DFOperator(proxy)
  }
  override def toString() = col_name
  def cname() = col_name
  def dtype() = type_name
}

