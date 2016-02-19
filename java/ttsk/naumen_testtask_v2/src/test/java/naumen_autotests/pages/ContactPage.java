package naumen_autotests.pages;

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

    /**
    * init driver, maybe should be moved in abstract class?
    * */
    public ContactPage() {
        FirefoxProfile profile = new FirefoxProfile();
        profile.setPreference("javascript.enabled", true);
        driver = new FirefoxDriver(profile);
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("http://samples.gwtproject.org/samples/Showcase/Showcase.html#!CwCellList");
    }

    private void setInput(String value, WebElement input) {
        input.click();
        input.clear();
        input.sendKeys(value);
    }

    /**
     * @return count of all contacts in contact list
     * */
    public int getContactCount() {
        return Integer.parseInt(driver.findElement(By.xpath("//div[@dir='ltr']")).getText().split(":")[1].trim());
    }

    /**
     * @return low boundary of shown contacts in contact list
     * */
    public int getShownContactCount() {
        return Integer.parseInt(driver.findElement(By.xpath("//div[@dir='ltr']"))
                .getText().split(":")[0].split("-")[1].trim());
    }

    /**
     * scrolls lost down one time
     * */
    public void scrollList() {
        int contact_count = this.getContactCount();
        int contact_shown = this.getShownContactCount();
        if (contact_count <= contact_shown) {
            return;
        }
        while (contact_shown == this.getShownContactCount()) {
            driver.findElement(By.xpath("//div[@class='GNHGC04CJJ']")).sendKeys(Keys.PAGE_DOWN);
        }

    }

    /**
     * scroll list down till the end of list
     * */
    public void scrollListToBottom() {
        WebElement contacts_container  = driver.findElement(By.xpath("//div[@class='GNHGC04CJJ']"));
        int amount = this.getContactCount();
        int shown = this.getShownContactCount();
        while (shown < amount) {
            contacts_container.sendKeys(Keys.PAGE_DOWN);
            shown = this.getShownContactCount();
        }
    }

    /**
     * @return contact element (div) by index in contact list
     * */
    public WebElement getElementByRow(int row) {
        String xpath = String.format("//div[@__idx='%d']", row);
        return driver.findElement(By.xpath(xpath));
    }

    /**
     * clicks on "Create contact button"
     * */
    public void createContactClick() {
        driver.findElement(By.xpath("//button[contains(text(), 'Create Contact')]")).click();
    }

    /**
     * clicks on "Update contact button"
     * */
    public void updateContactClick() {
        driver.findElement(By.xpath("//button[contains(text(), 'Update Contact')]")).click();
    }

    /**
     * clicks on "generate 50 contacts button"
     * */
    public void generateNew50Contacts() {
        driver.findElement(By.xpath("//button[contains(text(), 'Generate 50 Contacts')]")).click();
    }

    /**
     * @return name (first + last) of contact specified by index
     * */
    public String getElementNameByRow(int row) {
        WebElement el = this.getElementByRow(row);
        return el.findElement(By.xpath("(.//td)[2]")).getText();
    }

    /**
     * @param name - string to set as first name
     * set first name input
     * */
    public void setInputFirstName(String name) {
        WebElement name_input  = driver.findElement(By.xpath("(//input[@class='gwt-TextBox'])[1]"));
        setInput(name, name_input);
    }

    /**
     * @param name - string to set as last name
     * set last name input
     * */
    public void setInputLastName(String name) {
        WebElement name_input  = driver.findElement(By.xpath("(//input[@class='gwt-TextBox'])[2]"));
        setInput(name, name_input);
    }

    /**
     * @param date - string to set as fdate
     * set birthday input
     * */
    public void setInputDate(String date) {
        WebElement date_input  = driver.findElement(By.xpath("//input[@class='gwt-DateBox']"));
        setInput(date, date_input);
    }

    /**
     * @param address - string to set as address
     * set address input
     * */
    public void setInputAddress(String address) {
        WebElement adress_input  = driver.findElement(By.xpath("//textarea[@class='gwt-TextArea']"));
        setInput(address, adress_input);
    }

    public void quit() {
        driver.quit();
    }
}
