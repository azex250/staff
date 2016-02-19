package naumen_autotests;

import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.firefox.FirefoxProfile;

import java.util.concurrent.TimeUnit;

/**
 * Created by az on 27.01.16
 */
public class ContactPage {
    private WebDriver driver;

    public ContactPage() {
        FirefoxProfile profile = new FirefoxProfile();
        profile.setPreference("javascript.enabled", true);
        driver = new FirefoxDriver(profile);
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("http://samples.gwtproject.org/samples/Showcase/Showcase.html#!CwCellList");
    }

    public int getContactAmount() {
        return Integer.parseInt(driver.findElement(By.xpath("//div[@dir='ltr']")).getText().split(":")[1].trim());
    }

    public int getShownContactAmount() {
        return Integer.parseInt(driver.findElement(By.xpath("//div[@dir='ltr']"))
                .getText().split(":")[0].split("-")[1].trim());
    }

    public void scrollListToBottom() {
        WebElement contacts_container  = driver.findElement(By.xpath("//div[@class='GNHGC04CJJ']"));
        int amount = this.getContactAmount();
        int shown = this.getShownContactAmount();
        while (shown < amount) {
            contacts_container.sendKeys(Keys.PAGE_DOWN);
            shown = this.getShownContactAmount();
        }
    }

    public WebElement getElementByRow(int row) {
        String xpath = String.format("//div[@__idx='%d']", row);
        return driver.findElement(By.xpath(xpath));
    }

    public void createContactClick() {
        driver.findElement(By.xpath("//button[contains(text(), 'Create Contact')]")).click();
    }

    public void updateContactClick() {
        driver.findElement(By.xpath("//button[contains(text(), 'Update Contact')]")).click();
    }

    public void quit() {
        driver.quit();
    }

    public String getElementNameByRow(int row) {
        WebElement el = this.getElementByRow(row);
        return el.findElement(By.xpath("(.//td)[2]")).getText();
    }

    public void setInputName(String name) {
        WebElement name_input  = driver.findElement(By.xpath("(//input[@class='gwt-TextBox'])[1]"));
        name_input.click();
        name_input.clear();
        name_input.sendKeys(name);
    }

    public void setInputDate(String date) {
        WebElement date_input  = driver.findElement(By.xpath("//input[@class='gwt-DateBox']"));
        date_input.click();
        date_input.clear();
        date_input.sendKeys(date);
    }

    public String getFormDate() {
        return driver.findElement(By.xpath("//input[@class='gwt-DateBox']")).getText();
    }
}
