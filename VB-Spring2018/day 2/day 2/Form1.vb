Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Application.Exit()
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim i As Integer

        If ListBox1.SelectedIndex = 0 Then
            Select Case ComboBox1.Text
                Case "Manager"
                    Label5.Text = FormatCurrency(100000, 0)
                Case "Worker"
                    Label5.Text = FormatCurrency(50000, 0)
                Case "Peon"
                    Label5.Text = FormatCurrency(1, 0)
                Case Else
                    Label5.Text = FormatCurrency(6545242757, 0)
            End Select
        ElseIf ListBox1.SelectedIndex = 1 Then
            i = ListBox1.SelectedIndex
            Label5.Text = ListBox1.Items(i)
        ElseIf ListBox1.SelectedIndex = 2 Then
            Select Case ComboBox1.Text
                Case "Manager"
                    Label5.Text = "Managers"
                Case "Worker"
                    Label5.Text = "Workers"
                Case "Peon"
                    Label5.Text = "Peons"
                Case Else
                    Label5.Text = ComboBox1.Text
            End Select
        Else
            Label5.Text = "?"
        End If
    End Sub

    Private Sub RadioButton1_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton1.CheckedChanged
        RadioButton2.Checked = False
        Me.BackColor = Color.SteelBlue

    End Sub

    Private Sub RadioButton2_CheckedChanged(sender As Object, e As EventArgs) Handles RadioButton2.CheckedChanged
        RadioButton1.Checked = False
        Me.BackColor = Color.MediumSeaGreen

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        RadioButton1.Checked = True
        RadioButton2.Checked = False

    End Sub
End Class
