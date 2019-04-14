/// Ekle.java Kodları
package mssql2012connection;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

//Bağlan Sınıfımızdan miras alıyoruz ve bağlantıyı açıyoruz.
public class Ekle extends Baglan{
    // Constructor oluşturuyoruz ve içersine ekleyeceğimiz verileri alıyoruz.
    public Ekle(Connection con,String sorgu,String ad,String soyad,int tc,int yas,String cinsiyet) {
        super(con);
        try {
// PreparedStatement nesnesi oluşturup gelen ekleme sorgusunu veritabanımıza gönderiyoruz.
            PreparedStatement prepare = con.prepareStatement(sorgu);
            prepare.setString(1,ad); // Buradaki 1 veritabanındaki ilk alan olan ad alanı ad ise alan //adı olan ad
            prepare.setString(2, soyad);
            prepare.setInt(3,tc);
            prepare.setInt(4,yas);
            prepare.setString(5,cinsiyet);
            prepare.executeUpdate(); // Verileri Ekledikten sonra veritabanını güncelliyoruz.
             System.out.println("Ekleme işlemi başarılı.");
        } catch (SQLException ex) {
            Logger.getLogger(Ekle.class.getName()).log(Level.SEVERE, null, ex);
        }
           }
    }


