import java.io.*;
public FileWriterTester {
    public void main(String[] args) throws IOException {
        String fileName = "E:\\Hello.txt";
        FileWriter writer = new FileWriter(fileName);
        writer.write("Hello World!!!\n");
        writer.close();
    }
}
