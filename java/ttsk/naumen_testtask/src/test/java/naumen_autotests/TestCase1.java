package naumen_autotests;

/**
 * Created by az on 27.01.16.
 */

    import static org.junit.Assert.assertThat;
    import static org.hamcrest.CoreMatchers.equalTo;

    import org.junit.After;
    import org.junit.Before;
    import org.junit.Test;
    import org.openqa.selenium.WebElement;



public class TestCase1 {
    private ContactPage page;

    @Before
    public void setUp() {
        page = new ContactPage();
    }

    @Test
    public void runCase() {
        WebElement elem = page.getElementByRow(0);
        String el_class_before_select = elem.getAttribute("class");
        elem.click();
        page.createContactClick();
        elem = page.getElementByRow(0);
        String el_class_after_select = elem.getAttribute("class");
        assertThat(el_class_after_select, equalTo(el_class_before_select));
    }

    @After
    public void afterTests() {
        page.quit();
    }
}

