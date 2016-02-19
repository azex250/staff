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
public class TablePage {
    private WebDriver driver;

    public TablePage() {
        FirefoxProfile profile = new FirefoxProfile();
        profile.setPreference("javascript.enabled", true);
        driver = new FirefoxDriver(profile);
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("http://samples.gwtproject.org/samples/Showcase/Showcase.html#!CwCellTable");
    }

    /**
     * @return row specified bt index
     * */
    public WebElement getElementByRow(int row) {
        String xpath = String.format("//tr[@__gwt_row='%d']", row);
        return driver.findElement(By.xpath(xpath));
    }

    /**
     * @return name of row specified by index
     * */
    public String getContactFirstNameByRow(int row) {
        return getElementByRow(row).findElement(By.xpath("(.//td)[2]")).getText();
    };

    /**
     * @param row - index of wor which first name will be updated
     * @param name + string which will be set as new first name
     * */
    public void setContactFirstNameByRow(int row, String name) {
        WebElement first_name_cell = getElementByRow(row).findElement(By.xpath("(.//td)[2]"));
        first_name_cell.click();
        first_name_cell.findElement(By.xpath(".//input")).sendKeys(name);
        driver.findElement(By.xpath("//div[contains(text(), 'Cell Table')]")).click();
    };

    /**
     * go to the end of contacts table
     * */
    public void goToEnd() {
        driver.findElement(By.xpath("//img[@aria-label='Last page']")).click();
    }

    /**
     * @return count of all rows in contacts table
     * */
    public int getRowsCount() {
        return Integer.parseInt(driver.findElement(By.xpath("(//div[@class='gwt-HTML'])[2]")).getText().split("of")[1].trim());
    }

    /**
     * @return low boundary of shown contacts
     * */
    public int getRowsShownCount() {
        return Integer.parseInt(driver.findElement(By.xpath("(//div[@class='gwt-HTML'])[2]"))
                .getText().split("of")[0].split("-")[1].trim());
    }

    /**
     * sorting contacts table by first name
     * */
    public void sortByFirstName() {
        driver.findElement(By.xpath("//th[@__gwt_column='column-gwt-uid-12']")).click();
    }

    /**
     * moved contact table pagination to one step forward
     * */
    public void stepForward() {
        driver.findElement(By.xpath("//img[@aria-label='Next page']")).click();
    }

    public void quit() {
        driver.quit();
    }
}
