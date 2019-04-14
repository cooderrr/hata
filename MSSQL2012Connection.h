//Son olarak ise Ana Metodumuzu açıp bu classları çağırabiliriz. Böylelikle kodlarımızı Test edebiliriz.
package mssql2012connection;
import java.sql.*;

public class MSSQL2012Connection {
public static String ekleSorgusu;
public static Statement stmt;
public static Connection con = null;
    public static void main(String[] args) {
        System.out.println("Veri Tabanı Bağlantı işlemleri>>\n");
        try {
//Bir bağlantı nesnesi oluşturalım.SQLServer bağlantısı yapacağız.
//sqlserver://localhost olarak da yazabilirdik.
//  Database = kısmına oluşturduğumuz Ogrenci tablo ismini yazalım.
//user kısmına oturum ismi
//password kısmına ise verdiğimiz şifreyi yazalım
             con = DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;database=Ogrenci;user=sa;password=123456");
        } catch (Exception e) {
        }  
// Database’e Eklenecek veriler
        String ad = "Kemal";
        String soyad = "Sesigüzel";
        int tc = 1111111111;
        int yas = 30;
        String cinsiyet = "Erkek";
// Ekleme SQL sorgusu.
        ekleSorgusu ="INSERT INTO  Ogr_Bilgileri (ad,soyad,tc_kimlik_no,yas,cinsiyet) VALUES (?,?,?,?,?) ";
          Baglan baglantıKur = new Baglan(con); //Bağlantımızı açıyoruz.
//Ekleyecegimiz verileri gönderiyoruz sorgumuzla birlikte
          Ekle veriEkle = new Ekle(con,ekleSorgusu,ad,soyad,tc,yas,cinsiyet);
// Guncellenecek Verileri gönderioruz
Sil veriSil = new Sil(con, 1333); 
//Tc kimlik numarası 1333 olan veriyi siliyoruz.
//Tüm verileri ekrana yazdırma
          VerileriGoster kayitlariGoster = new VerileriGoster(con);
    }  
}
//Database’imize veriler ekledim.
