Public Class Form1
    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        MessageBox.Show("Enter information in the textboxes and click 'Calculate My Mortgage' for your monthly mortgage payment.")
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Application.Exit()
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        NumericUpDown1.Text = ""
        NumericUpDown2.Text = ""
        NumericUpDown3.Text = ""
        NumericUpDown4.Text = ""
        Label6.Text = ""
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        '' R is monthly
        '' P is price left after downpayment, i is monthly interest rate, n is months(?)
        ''
        '' 4 is price, 3 is down, 2 is term length in years, 1 is yearly interest
        ''
        ''     P * i * (1 + i) ^ n
        '' R = -------------------
        ''       (1 + i) ^ n - 1

        Dim r, p, i, n As Double
        p = NumericUpDown4.Value - NumericUpDown3.Value
        i = NumericUpDown1.Value / 12 / 100
        n = NumericUpDown2.Value * 12

        r = (p * i * ((1 + i) ^ n)) / (((1 + i) ^ n) - 1)

        Label6.Text = "Your monthly payment is " + FormatCurrency(r)
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Label6.Text = ""
    End Sub
End Class
