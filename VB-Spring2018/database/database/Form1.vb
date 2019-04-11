Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.StudentsTableAdapter.Fill(Me.Database2DataSet.Students)
        Me.DataGridView1.BeginEdit(True)

        BindingNavigator1.BindingSource = StudentsBindingSource
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Application.Exit()
    End Sub

    Private Sub SaveToolStripButton_Click(sender As Object, e As EventArgs) Handles SaveToolStripButton.Click
        Me.Validate()
        Me.StudentsBindingSource.EndEdit()
        Me.StudentsTableAdapter.Update(Database2DataSet)
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Me.Validate()
        Me.StudentsBindingSource.EndEdit()
        Me.StudentsTableAdapter.Update(Database2DataSet)
    End Sub
End Class